/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:46:25 by kojwatan          #+#    #+#             */
/*   Updated: 2023/11/21 18:07:47 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sysexits.h>
# include <stdio.h>

void		run_cmd1(int infile_fd, int pipe_rd_wr[2], const char *path,
				const char *cmd_args);
void		run_cmd2(int outfile_fd, int pipe_rd_wr[2], const char *path,
				const char *cmd_args);
const char	*get_shell_basename(char *env[]);
void		exit_on_failure(const char *err_message);
char		*extract_cmd(char *str);
int			check_absopath(char *cmd);
const char	*get_path(char *cmd, char *env[]);
void		open_infile_outfile(int fds_infile_outfile[2], char *infile,
				char *outfile, char *env[]);

#endif