/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 00:08:52 by jobailla          #+#    #+#             */
/*   Updated: 2016/12/20 00:22:21 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "./libft/libft.h"

typedef struct		s_line
{
	struct s_line	*next;
	struct s_line	*prev;
}					t_line;

int		get_next_line(const int fd, char **line);

#endif
