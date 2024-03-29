/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:28:25 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/12/27 17:56:39 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc(t_data *data, t_container *con, int type)
{
	int		tmpfile_fd;
	int		status;
	pid_t	pid;

	ms_sigset(SIG_IGN, SIG_IGN);
	pid = fork();
	if (pid == -1)
		error_print(errno);
	if (pid == 0)
	{
		ms_sigset(SIG_DFL, SIG_IGN);
		tmpfile_fd = open(data->infile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (tmpfile_fd < 0)
			error_print(errno);
		read_heredoc(data, con, tmpfile_fd, type);
		exit(0);
	}
	wait(&status);
	con->exit_code = WEXITSTATUS(status);
	return (wait_heredoc(data, status, con));
}

void	read_heredoc(t_data *data, t_container *con, int tmpfile_fd, int type)
{
	char	*line;

	while (42)
	{
		line = readline("> ");
		if (!line)
			return ;
		if (!line[0])
			continue ;
		if (!ft_strncmp(data->delimeter, line, ft_strlen(data->delimeter))
			&& ft_strlen(data->delimeter) == (ft_strlen(line)))
			return ;
		if (type == 4)
			line = heredoc_expend(line, con->envp);
		write(tmpfile_fd, line, ft_strlen(line));
		write(tmpfile_fd, "\n", 1);
		free(line);
	}
	free(line);
	close(tmpfile_fd);
}

int	wait_heredoc(t_data *data, int status, t_container *con)
{
	if (WIFSIGNALED(status) != 0)
	{
		unlink(data->infile);
		write(1, "\n", 1);
		ms_sigset(sig_newline, SIG_IGN);
		con->exit_code = 1;
		return (0);
	}
	ms_sigset(sig_newline, SIG_IGN);
	con->exit_code = 0;
	return (1);
}

char	*get_heredoc_tmpfile_name(void)
{
	int		tmp_num;
	char	*tmp;
	char	*itoa_num;

	tmp_num = INT32_MIN;
	while (tmp_num <= INT32_MAX)
	{
		itoa_num = ft_itoa(tmp_num);
		tmp = ft_strjoin("/tmp/.", itoa_num);
		free(itoa_num);
		if (access(tmp, F_OK) == -1)
			return (tmp);
		free(tmp);
		tmp_num++;
	}
	return (NULL);
}

void	delete_all_heredoc_tmpfile(t_data *head)
{
	while (head != NULL)
	{
		if (head->delimeter != NULL)
			unlink(head->infile);
		head = head->next;
	}
}
