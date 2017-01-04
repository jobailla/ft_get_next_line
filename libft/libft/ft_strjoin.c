/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <jobailla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 12:00:55 by jobailla          #+#    #+#             */
/*   Updated: 2016/11/14 14:11:13 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(str = ft_strnew(len)))
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		return (str);
	}
	return (NULL);
}
