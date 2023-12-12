#include "minishell.h"

char	**make_cmd(t_list *list)
{
	t_list 	*tmp;
	int		i;
	int		len;
	char	**cmd;

	tmp = list;
	len = 0;
	while (tmp != NULL && !(tmp->type <= -1 && tmp->type >= -3))
	{
		if (tmp->type == 0)
			len++;
		tmp = tmp->next;
	}
	//printf("2d_arr_cmd_len -> %d\n", len);
	cmd = (char **)malloc((len + 1) * sizeof(char *));
	if (cmd == NULL)
		exit(1); // TODO: error handling
	i = 0;
	while (i < len)
	{
		if (list->type == 0)
			cmd[i++] = ft_strdup(list->data);
		list = list->next;
	}
	cmd[i] = NULL;
	return (cmd);
}

int		get_cmd_arr_len(t_list *lst)
{
	int	len;

	len = 1;
	while (lst != NULL)
	{
		if (lst->type == -1)
			len++;
		if (lst->type == -2 || lst->type == -3)
			break;
		lst = lst->next;
	}
	return (len);
}

t_list	*check_type_and_move_list(t_data *data, t_list *list)
{
	while (list != NULL)
	{
		if (list->type == -1)
			return (list->next);
		else if (list->type == -2 || list->type == -3)
		{
			data->outfile = list->next->data;
			return (list->next);
		}
		else if (list->type == -4)
			data->infile = list->next->data;
		list = list->next;
	}
	return (list);
}

char	***make_cmd_arr(t_data *data, t_list *list)
{
	t_list	*tmp;
	char	***cmd_arr;
	int		i;
	int		len;

	i = 0;
	tmp = list;
	len = get_cmd_arr_len(list);
	data->cnt = len;
	//printf("3d_arr_cmd_len -> %d\n", len);
	cmd_arr = (char ***)malloc((len + 1) * sizeof(char **));
	if (cmd_arr == NULL)
		exit(1); // TODO: error handling
	while (i < len)
	{
		cmd_arr[i] = make_cmd(list);
		i++;
		list = check_type_and_move_list(data, list);
	}
	cmd_arr[i] = NULL;
	return (cmd_arr);
}

void	init_data(t_data *data, t_list *list)
{
	data->infile = NULL;
	data->outfile = NULL;
	data->cmd_arr = make_cmd_arr(data, list);
}
