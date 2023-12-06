/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:05:00 by kojwatan          #+#    #+#             */
/*   Updated: 2023/11/21 19:36:05 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	run_cmd1(int infile_fd, int pipe_rd_wr[2], const char *path,
		const char *cmd_args)
{
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	close(pipe_rd_wr[0]);
	dup2(pipe_rd_wr[1], STDOUT_FILENO);
	close(pipe_rd_wr[1]);
	execve(path, ft_split(cmd_args, ' '), NULL);
	exit(EXIT_FAILURE);
}

void	run_cmd2(int outfile_fd, int pipe_rd_wr[2], const char *path,
		const char *cmd_args)
{
	close(pipe_rd_wr[1]);
	dup2(pipe_rd_wr[0], STDIN_FILENO);
	close(pipe_rd_wr[0]);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	execve(path, ft_split(cmd_args, ' '), NULL);
	exit(EXIT_FAILURE);
}

const char	*get_shell_basename(char *env[])
{
	const char	*shell_name;

	while (*env)
	{
		if (ft_strncmp(*env, "SHELL", 5) == 0)
			shell_name = *env;
		env++;
	}
	return (ft_strrchr(shell_name, '/') + 1);
}

void	exit_on_failure(const char *err_message)
{
	perror(err_message);
	exit(EXIT_FAILURE);
}

char	*extract_cmd(char *str)
{
	char	*cmd;
	int		len;

	len = 0;
	while (str[len] && str[len] != ' ')
		len++;
	cmd = malloc(len + 1);
	len = 0;
	while (str[len] && str[len] != ' ')
	{
		cmd[len] = str[len];
		len++;
	}
	cmd[len] = 0;
	return (cmd);
}

int	check_absopath(char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (1);
	else
		return (0);
}

const char	*get_path(char *cmd, char *env[])
{
	char		*env_path;
	char		*tmp;
	char		**split_paths;
	const char	*path;

	path = NULL;
	while (*env)
	{
		if (ft_strncmp(*env, "PATH", 4) == 0)
			env_path = *env;
		env++;
	}
	if (ft_strchr(cmd, '/'))
	{	
		if (check_absopath(cmd))
			return (cmd);
	}
	else
	{
		tmp = cmd;
		cmd = ft_strjoin("/", cmd);
		free(tmp);
		split_paths = ft_split(env_path + 5, ':');
		while (*split_paths)
		{
			*split_paths = ft_strjoin(*split_paths, cmd);
			if (path == NULL && access(*split_paths, X_OK) == 0)
				path = ft_strdup(*split_paths);
			free(*split_paths);
			split_paths++;
		}
		free(cmd);
	}
	if (path == NULL)
		exit_on_failure("command not found\n");
	return (path);
}

void	open_infile_outfile(int fds_infile_outfile[2], char *infile,
		char *outfile, char *env[])
{
	fds_infile_outfile[0] = open(infile, O_RDONLY);
	fds_infile_outfile[1] = open(outfile, O_WRONLY | O_TRUNC | O_CREAT);
	if (fds_infile_outfile[0] == -1 || fds_infile_outfile[1] == -1)
		exit_on_failure(get_shell_basename(env));
}

int	main(int ac, char *av[], char *env[])
{
	int	pid;
	int	pipe_rd_wr[2];
	int	fds_infile_outfile[2];

	if (ac != 5)
		return (0);
	open_infile_outfile(fds_infile_outfile, av[1], av[4], env);
	if (pipe(pipe_rd_wr) == -1)
		exit_on_failure("pipe");
	pid = fork();
	if (pid == 0)
		run_cmd1(fds_infile_outfile[0], pipe_rd_wr, get_path(extract_cmd(av[2]),
				env), av[2]);
	else if (pid > 0)
	{
		wait(NULL);
		pid = fork();
		if (pid == 0)
			run_cmd2(fds_infile_outfile[1], pipe_rd_wr,
				get_path(extract_cmd(av[3]), env), av[3]);
		else if (pid < 0)
			exit_on_failure("fork");
	}
	else
		exit_on_failure("fork");
	return (0);
}
