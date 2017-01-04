/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <jobailla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 12:05:06 by jobailla          #+#    #+#             */
/*   Updated: 2016/11/20 17:01:57 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	nbr;

	len = ft_nbrlen(n);
	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = nbr % 10 + '0';
	while (nbr /= 10)
		str[--len] = nbr % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
