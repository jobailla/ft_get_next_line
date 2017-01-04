/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <jobailla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 12:03:27 by jobailla          #+#    #+#             */
/*   Updated: 2016/11/20 16:37:41 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		start;
	int		end;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (!(s))
		return (NULL);
	if (!(tab = (char **)ft_memalloc(sizeof(char *)
	* (ft_count_word(s, c) + 1))))
		return (NULL);
	while (s[j] && i < ft_count_word(s, c))
	{
		end = 0;
		while (s[j] == c)
			j++;
		start = j;
		while (s[j++] != c)
			end++;
		if (!(tab[i++] = ft_strsub(s, start, end)))
			return (NULL);
	}
	return (tab);
}
