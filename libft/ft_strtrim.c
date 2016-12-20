/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobailla <jobailla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 12:02:09 by jobailla          #+#    #+#             */
/*   Updated: 2016/11/16 01:36:57 by jobailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		end;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (ft_isblank_and_newline(s[start]))
		start++;
	while (ft_isblank_and_newline(s[end - 1]))
		end--;
	if (s[start] == '\0')
		return (ft_strdup("\0"));
	else
		return (ft_strsub(s, start, end - start));
}
