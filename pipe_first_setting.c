/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_first_setting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:13:01 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/12/08 12:40:29 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	first_setting(int ac, char **av, t_data *data, char **env)
{
	int	i;

	data->pipe = (int **)malloc(sizeof(int *) * (ac - 4));
	data->id = (pid_t *)malloc(sizeof(pid_t) * (ac - 3));
	if (data->pipe == 0 || data->id == 0)
		error_print(errno);
	i = 0;
	while (i < ac - 4)
	{
		data->pipe[i] = (int *)malloc(sizeof(int) * 2);
		if (data->pipe[i] == 0)
			error_print(errno);
		i++;
	}
	data->path = path_setting(env);
	data->cmd_num = ac - 3;
	data->cmd = av + 2;
}

void	heredoc_setting(int ac, char **av, t_data *data, char **env)
{
	int	i;

	data->pipe = (int **)malloc(sizeof(int *) * (ac - 5));
	data->id = (pid_t *)malloc(sizeof(pid_t) * (ac - 4));
	if (data->pipe == 0 || data->id == 0)
		error_print(errno);
	i = 0;
	while (i < ac - 4)
	{
		data->pipe[i] = (int *)malloc(sizeof(int) * 2);
		if (data->pipe[i] == 0)
			error_print(errno);
		i++;
	}
	data->path = path_setting(env);
	data->cmd_num = ac - 4;
	data->cmd = av + 3;
}

char	**path_setting(char **env)
{
	char	**env_path;
	int		i;

	i = 0;
	while (*env && ft_strncmp(*env, "PATH=", 5) != 0)
		env++;
	if (*env == 0)
		*env = "PATH=/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:";
	(*env) += 5;
	env_path = ft_split(*env, ':');
	if (env_path == 0)
		error_print(errno);
	return (env_path);
}

char	*path_search(char **env, char *command)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = 0;
	if (ft_strchr(command, '/') && access(command, F_OK) == 0)
		return (command);
	if (ft_strchr(command, '/'))
		command_error(command);
	while (env[i])
	{
		tmp = px_strjoin(env[i++], command, "/");
		if (tmp == 0)
			error_print(errno);
		if (access(tmp, F_OK) == 0)
			break ;
		free(tmp);
		tmp = 0;
	}
	if (tmp == 0)
		command_error(command);
	return (tmp);
}

void	command_error(char *command)
{
	ft_putstr_fd("mish: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}
