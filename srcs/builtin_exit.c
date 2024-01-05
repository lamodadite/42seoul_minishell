/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:55:45 by hyeongsh          #+#    #+#             */
/*   Updated: 2024/01/05 15:20:00 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exit_error_check(char **cmds);

int	builtin_exit(char **cmds, t_container *con, int flag)
{
	int	i;
	int	exitcode;

	if (flag == 0)
		printf("exit\n");
	i = 0;
	while (cmds[i])
		i++;
	if (i == 1 && g_signal == 0 && flag == 0)
		exit(con->exit_code);
	else if (i == 1 && g_signal == 1 && flag == 0)
		exit(1);
	else if (i == 1 && flag == 1)
		exit(0);
	exitcode = exit_error_check(cmds);
	if (i > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	exit(exitcode);
}

static int	exit_error_check(char **cmds)
{
	int	j;

	j = 0;
	if (ft_strlen(cmds[1]) > 20 || (ft_strlen(cmds[1]) == 20
			&& ft_strncmp(cmds[1], "9223372036854775807", 20) > 0))
	{
		print_execute_error("exit", cmds[1], "numeric argument required");
		exit(255);
	}
	while (cmds[1][j])
	{
		if (ft_isdigit(cmds[1][j]) == 0 && cmds[1][j] != '+'
			&& cmds[1][j] != '-')
		{
			print_execute_error("exit", cmds[1], "numeric argument required");
			exit(255);
		}
		j++;
	}
	return (ft_atoi(cmds[1]));
}
