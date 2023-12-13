/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:50:33 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/12/13 21:15:13 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_list	*head;
	char	*line;
//	t_data	*data;

	(void) ac;
	(void) av;
	(void) envp;
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
			while (tmp != NULL)
			{
				printf("data: [%s] type: [%d] \n", tmp->data, tmp->type);
				tmp = tmp->next;
			}
//			data = make_data_list(tmp);
			//print_data(&data);
//			pipex(&data);
			// TODO: clear data
		}
		ft_lstclear(&head, free);
		free(line);
	}
	return (0);
}
