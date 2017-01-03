/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 00:22:31 by jobailla          #+#    #+#             */
/*   Updated: 2017/01/03 03:52:36 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		ft_check_line(char	*str)
{
	if (str)
	{
		if (ft_strchr(str,'\n'))
			return (1);
		if (ft_strchr(str,'\0'))
			return (2);
	}
	return (-1);
}

static	t_gnl	*ft_init_list(int	fd)
{
	t_gnl	*list;

	if (!(list = ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	list->fd = fd;
	list->line = NULL;
	list->next = NULL;
	return (list);
}

static	t_gnl	*ft_add_list(t_gnl	*list, int fd)
{
	t_gnl	*tmp;

	tmp = list;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = ft_init_list(fd);
	return (tmp->next);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*list;
	t_gnl			*tmp;
	int				ret;

	if (line == NULL || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	list = ft_init_list(fd);
	while (tmp)
		tmp = tmp->next;
	if (!tmp)
		tmp = ft_add_list(list, fd);
	return (0);
}
