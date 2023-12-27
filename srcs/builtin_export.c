/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:31:43 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/12/27 17:56:17 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**add_env(char *var_name, char *var, t_container *con)
{
	char	**ret;
	int		flag;
	int		i;

	if (ft_strchr(var, '=') == NULL)
		return (NULL);
	ret = (char **)ft_calloc(sizeof(char *), get_2d_arr_len(con->envp) + 2);
	flag = 0;
	i = -1;
	while (con->envp[++i] != NULL)
	{
		ret[i] = con->envp[i];
		if (ft_strncmp(ret[i], var, ft_strlen(var_name) + 1) == 0 && flag == 0)
		{
			free(ret[i]);
			ret[i] = ft_strdup(var);
			flag = 1;
		}
	}
	if (flag == 0)
		ret[i] = ft_strdup(var);
	return (ret);
}

char	*get_var_name(char *cmd)
{
	char	*tmp;

	tmp = ft_strchr(cmd, '=');
	if (tmp == NULL)
		return (ft_strdup(cmd));
	return (ft_substr(cmd, 0, tmp - cmd));
}

int	builtin_export(char **cmds, t_container *con, int flag)
{
	char	*var_name;
	char	**ret;
	int		i;

	i = 0;
	if (cmds[1] == NULL)
		return (builtin_env(con->envp));
	while (cmds[++i] != NULL)
	{
		var_name = get_var_name(cmds[i]);
		if (check_identifier(var_name) != 0)
		{
			free(var_name);
			flag = print_execute_error("export", cmds[i],
					"not a valid identifier");
			continue ;
		}
		ret = add_env(var_name, cmds[i], con);
		free(var_name);
		if (ret == NULL)
			return (0);
		free(con->envp);
		con->envp = ret;
	}
	return (flag);
}
