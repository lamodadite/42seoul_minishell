/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:53:34 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/12/12 15:36:41 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

struct sigaction	sig;

typedef struct s_data
{
	char	*infile;
	char	*outfile;
	char	***cmd_arr;
	int		cnt;
}	t_data;

/* hyeongsh pipex
char	*px_strjoin(char const *s1, char const *s2, char *sep);
void	error_print(int flag);
char	**path_setting(char **env);
char	*path_search(char **env, char *command);
int		open_check(int ac, char **av, int *fd, char **heredoc);
void	first_setting(int ac, char **av, t_data *data, char **env);
void	make_child(t_data *data, char **av, int i, char **env);
void	command_exec_first(t_data *data, char **av, char **env);
void	command_exec_mid(t_data *data, int i, char **env);
void	command_exec_end(t_data *data, char **env);
void	close_pipe(t_data *data, int i);
void	make_heredoc(char **av, char **heredoc);
void	heredoc_setting(int ac, char **av, t_data *data, char **env);
int		ending(t_data *data, char *heredoc);
void	ending_free(t_data *data);
void	make_child_heredoc(t_data *data, char *heredoc, char **env);
void	command_exec_first_heredoc(t_data *data, char *heredoc, char **env);
void	command_exec_end_heredoc(t_data *data, char **env);
void	command_error(char *command);
*/

t_list	*pasing(char *line);
void	split_free(char **command);
void	error_print(int flag);

int		ms_init(char c, char *s);
int		ms_split_input(char *toss, char **cmd, char *oper);
int		ms_split_first(char *toss, char **cmd, char *oper);
int		ms_split_plus(char *toss, int *i, char **cmd);
char	**ms_split(char *cmd);

/* debug */
void	print_2d_arr(char **s);
void	print_3d_arr(char ***s);
void	print_node(t_list *list);
void	print_data(t_data *data);

/* init_data */
char	**make_cmd(t_list *list);
int		get_cmd_arr_len(t_list *lst);
t_list	*check_type_and_move_list(t_data *data, t_list *list);
char	***make_cmd_arr(t_data *data, t_list *list);
void	init_data(t_data *data, t_list *list);

/* pipex
void	init_info(t_info *info, int ac, char **av, char **envp);
int		wait_children(t_info *info);
void	child(t_info *info);
void	here_doc(t_info *info);
int		pipex_main(int ac, char **av, char **envp);
char	*get_env_path(char **envp);
char	*make_cmd_path(char const *path, char const *cmd);
char	*get_valid_path(char **cmds, char *env_path);
int		execute_cmd(t_info *info);
void	open_pipe(t_info *info);
void	close_pipe(t_info *info);
void	open_file(t_info *info);
void	close_all_pipe(t_info *info);
void	dup2_sub(int first, int second);
void	free_2d_array(char **arr);
void	perror_exit(char *str, int exit_code);
*/

#endif
