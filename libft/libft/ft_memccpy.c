/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:22:11 by jobailla          #+#    #+#             */
/*   Updated: 2016/11/16 04:50:00 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char *d;
	unsigned char *s;
	unsigned char ch;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	ch = (unsigned char)c;
	while (len--)
	{
		*d = *s;
		if (*s == ch)
			return ((void *)d + 1);
		s++;
		d++;
	}
	return (NULL);
}
