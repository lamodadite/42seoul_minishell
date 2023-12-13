/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:28:00 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/12/13 16:13:51 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_init(char *s, char *data)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (data[j])
			if (s[i] == data[j++])
				return (j);
		i++;
	}
	return (-1);
}

static int	ft_typecheck(char *data)
{
	if (ft_strncmp("|", data, 2) == 0)
		return (-1);
	else if (ft_strncmp(">", data, 2) == 0)
		return (-2);
	else if (ft_strncmp(">>", data, 3) == 0)
		return (-3);
	else if (ft_strncmp("<", data, 2) == 0)
		return (-4);
	else if (ft_strncmp("<<", data, 3) == 0)
		return (-5);
	else if (ft_init("$", data) > -1)
		return (5);
	printf("syntax error: %s\n", data);
	return (100);
}

t_list	*ft_lstnew(char *data)
{
	t_list	*toss;

	if (data == 0)
		return (0);
	toss = (t_list *)malloc(sizeof(t_list) * 1);
	if (toss == 0)
		return (0);
	toss->next = NULL;
	toss->prev = NULL;
	toss->data = data;
	if (ft_init("$|&<>;\\", data) > -1)
		toss->type = ft_typecheck(data);
	else
		toss->type = 0;
	return (toss);
}
