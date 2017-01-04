/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 00:08:52 by jobailla          #+#    #+#             */
/*   Updated: 2017/01/04 22:41:47 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/includes/libft.h"

# define BUFF_SIZE 1

typedef struct		s_gnl
{
	int				fd;
	char			buf[BUFF_SIZE + 1];
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
