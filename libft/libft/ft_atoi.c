/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 09:57:20 by jobailla          #+#    #+#             */
/*   Updated: 2016/12/23 19:10:25 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		ret;
	int		sign;

	ret = 0;
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + *str - '0';
		str++;
	}
	return (ret * sign);
}
