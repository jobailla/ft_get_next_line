/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:33:43 by jobailla          #+#    #+#             */
/*   Updated: 2016/11/20 14:10:38 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	s = (char *)src;
	d = (char *)dst;
	if (dst < src)
		ft_memcpy(d, s, len);
	else
	{
		while (len--)
			d[len] = s[len];
	}
	return (dst);
}
