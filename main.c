/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:50:33 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/12/10 17:31:50 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_list	*head;
	char	*line;

	while (42)
	{
		line = readline("mish> ");
		if (!line)
			break ;
		add_history(line);
		head = pasing(line);
		if (head != NULL)
		{
			t_list	*tmp;
			tmp = head;
			while (tmp)
			{
				printf("=====================\ndata [%s] type : [%d]\n",
					tmp->data, tmp->type);
				tmp = tmp->next;
			}
		}
		ft_lstclear(&head, free);
		free(line);
	}
	return (0);
}

void	error_print(int flag)
{
	ft_putstr_fd("mish: ", 2);
	if (flag == 2)
		ft_putstr_fd("input: ", 2);
	ft_putstr_fd(strerror(flag), 2);
	ft_putstr_fd("\n", 2);
	if (flag == 126)
		exit(126);
	exit(1);
}
