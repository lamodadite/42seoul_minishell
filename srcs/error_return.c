/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:02:58 by jongmlee          #+#    #+#             */
/*   Updated: 2023/12/22 19:31:19 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_execute_error(char *cmd, char *path, char *error_msg)
{
	ft_putstr_fd("minishell", STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	return (1);
}

int	print_syntax_error(char *error_char, t_token **head, t_container *con)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(error_char, 2);
	ft_putstr_fd("\'\n", 2);
	con->exit_code = 258;
	ms_tokenclear(head, free);
	return (1);
}

int	print_builtin_file_error(char *file, t_container *con)
{
	struct stat	buf;

	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	if (stat(file, &buf) == -1)
		ft_putstr_fd("No such file or directory\n", 2);
	else
		ft_putstr_fd("Permission denied\n", 2);
	con->exit_code = 1;
	return (1);
}
