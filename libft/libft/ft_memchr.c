/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:19:35 by jobailla          #+#    #+#             */
/*   Updated: 2017/01/05 06:01:46 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char	*s;
	unsigned char	ch;

	s = (unsigned char *)src;
	ch = (unsigned char)c;
	while (len--)
	{
		if (*s == ch)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
