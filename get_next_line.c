/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 00:22:31 by jobailla          #+#    #+#             */
/*   Updated: 2017/01/04 22:44:43 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_gnl	*ft_find_fd_in_list(t_gnl **head, int const fd)
{
	t_gnl	*new;
	t_gnl	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (0 != (new = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
	{
		new->fd = fd;
		ft_bzero(new->buf, BUFF_SIZE + 1);
		new->next = *head;
		*head = new;
	}
	return (new);
}

static int		ft_look_for_buffer(t_gnl *item, char **line)
{
	char	*tmp;

	if ((tmp = ft_strchr(item->buf, '\n')))
		*tmp++ = '\0';
	if (!(*line = ft_strdup(item->buf)))
		return (-1);
	if (tmp)
	{
		ft_strcpy(item->buf, tmp);
		return (1);
	}
	bzero(item->buf, BUFF_SIZE + 1);
	return (0);
}

static int		ft_look_for_read(t_gnl *item, char **line)
{
	char	*tmp;
	char	*save;

	if ((tmp = ft_strchr(item->buf, '\n')))
		*tmp++ = '\0';
	save = *line;
	if (!(*line = ft_strjoin(*line, item->buf)))
	{
		ft_strdel(&save);
		return (-1);
	}
	ft_strdel(&save);
	if (tmp)
	{
		ft_strcpy(item->buf, tmp);
		return (1);
	}
	else
		return (0);
}

static int		ft_read_from_fd(t_gnl *item, char **line)
{
	int		ret;

	while ((ret = read(item->fd, item->buf, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		item->buf[ret] = '\0';
		ret = ft_look_for_read(item, line);
		if (ret != 0)
			return (ret);
	}
	return (ft_strlen(*line) != 0);
}

int				get_next_line(const int fd, char **line)
{
	static	t_gnl	*lst = NULL;
	t_gnl			*tmp;
	int				ret;

	if (line == NULL || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	tmp = ft_find_fd_in_list(&lst, fd);
	if (tmp == NULL)
		return (-1);
	ret = ft_look_for_buffer(tmp, line);
	if (!ret)
		ret = ft_read_from_fd(tmp, line);
	return (ret);
}
