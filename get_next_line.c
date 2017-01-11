/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 00:22:31 by jobailla          #+#    #+#             */
/*   Updated: 2017/01/09 09:09:09 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_gnl	*find_fd(t_gnl **head, int const fd)
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
	if (!(new = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
		return (0);
	new->fd = fd;
	ft_bzero(new->buf, BUFF_SIZE);
	new->next = *head;
	*head = new;
	return (new);
}

static int		look_buf(t_gnl *item, char **line)
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
	ft_bzero(item->buf, BUFF_SIZE);
	return (0);
}

static int		look_for_read(t_gnl *item, char **line)
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
	return (0);
}

static int		read_fd(t_gnl *item, char **line)
{
	int		ret;

	while ((ret = read(item->fd, item->buf, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		item->buf[ret] = '\0';
		ret = look_for_read(item, line);
		if (ret != 0)
			return (ret);
		ft_bzero(item->buf, BUFF_SIZE);
	}
	return (ft_strlen(*line) != 0);
}

int				get_next_line(const int fd, char **line)
{
	static	t_gnl	*lst = NULL;
	t_gnl			*tmp;
	int				ret;

	if (line == NULL || fd < 0 || BUFF_SIZE < 1 || !(tmp = find_fd(&lst, fd)))
		return (-1);
	ret = look_buf(tmp, line);
	if (!ret)
		ret = read_fd(tmp, line);
	return (ret);
}
