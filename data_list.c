#include "minishell.h"

void	init_data_node(t_data *node)
{
	node->infile = NULL;
	node->outfile = NULL;
	node->delimeter = NULL;
	node->cmd_arr = NULL;
	node->is_append = 0;
	node->next = NULL;
	node->prev = NULL;
}

int		get_cmd_arr_len(t_list *lst)
{
	int	len;

	len = 0;
	while (lst->type != -1)
	{
		if (lst->type == 0)
			len++;
		lst = lst->next;
	}
	return (len);
}

t_data	data_lstnew(t_list *line)
{
	t_data	*toss;
	int		len;

	if (line == NULL)
		return (NULL);
	toss = (t_data *)malloc(sizeof(t_data));
	if (toss == NULL)
		exit(1);
	init_data_node(toss);
	len = get_cmd_arr_len(line);
	while (line =! NULL && line->type != -1)
	{
		if (line->type == 1)
			toss->infile = ft_strdup(line->data);
		else if (line->type == 2)
			toss->delimeter = ft_strdup(line->data);
		else if (line->type == 3 || line->type == 4)
		{
			toss->outfile = ft_strdup(line->data);
			if (line->type == 4)
				toss->is_append = 1;
		}
	}
}

t_data	*make_data_list(t_list *line)
{
	t_data	*head;
	t_data	*tmp;

	while()
}

void	init_container(t_container *con, t_list *line, char **envp)
{
	con->cnt = 0;
	con->envp = ms_2d_arr_dup(envp);
	con->head = make_data_list(line);
}