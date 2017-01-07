/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:42:44 by jobailla          #+#    #+#             */
/*   Updated: 2017/01/07 13:33:36 by jobailla         ###   ########.fr       */
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
			printf("\x1b[32m-> [%d] SORTIE GNL : %s\n", i, line);
		}
		if (i == 0)
			printf("\x1b[33m-> [%d] SORTIE GNL : %s\n", i, line);
		if (i == (-1))
			printf("\x1b[31m-> [%d] SORTIE GNL : %s\n", i, line);
		printf("\x1b[36mindex read line : %d\n", c);
		printf("\x1b[35mindex fd	: %d\n", x);
		x++;
	}
}
