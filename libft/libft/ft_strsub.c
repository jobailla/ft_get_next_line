/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <jobailla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 11:59:18 by jobailla          #+#    #+#             */
/*   Updated: 2017/01/03 18:02:59 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)ft_memalloc(sizeof(*str) * len + 1)))
		return (NULL);
	if (s)
	{
		while (len--)
			str[i++] = s[start++];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
