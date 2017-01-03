/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 00:08:52 by jobailla          #+#    #+#             */
/*   Updated: 2017/01/03 04:05:19 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "./libft/libft.h"

# define BUFF_SIZE 2048

typedef struct		s_gnl
{
	int				fd;
	size_t			size;
	char			*line;
	struct s_gnl	*next;
//	struct s_gnl	*prev;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
