/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 10:15:19 by jobailla          #+#    #+#             */
/*   Updated: 2017/01/07 10:15:04 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2 != NULL)
		ft_strcpy(s2, s1);
	return (s2);
}
