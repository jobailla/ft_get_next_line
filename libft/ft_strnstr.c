/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <jobailla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 23:54:39 by jobailla          #+#    #+#             */
/*   Updated: 2016/11/20 15:17:44 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if ((little[0] == '\0' || ft_isspace(*little == 1)) && (big))
		return (char *)big;
	while (big[i] && i <= len)
	{
		j = 0;
		while (little[j] == big[j + i] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return (char *)big + i;
			j++;
		}
		i++;
	}
	return (0);
}
