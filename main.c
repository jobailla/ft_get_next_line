/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:42:44 by jobailla          #+#    #+#             */
/*   Updated: 2017/01/09 09:28:58 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int			main(int ac,	char **av)
{
	int		i;
	int		j;
	int		c;
	int		x;
	int		fd;
	char	*line;

	i = 0;
	j = 0;
	x = 1;
	line = NULL;
	while (ac > x)
	{
		c = 0;
		fd = open(av[x], O_RDONLY);
		while((i = get_next_line(fd, &line)) > 0)
		{
			c++;
			printf(GRN"[%d] SORTIE GNL : %s\n" NRM, i, line);
		}
		if (i == 0)
			printf(YEL"[%d] SORTIE GNL : %s\n" NRM, i, line);
		if (i == (-1))
			printf(RED"[%d] SORTIE GNL : %s\n" NRM, i, line);
		printf(CYN"index read line : %d\n " NRM, c);
		printf(MAG"index fd	: %d\n" NRM, x);
		x++;
	}
}
