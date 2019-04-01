/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:45:33 by jnabet            #+#    #+#             */
/*   Updated: 2018/11/22 13:49:21 by jnabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	res = (char*)s1;
	if (s2[i] == '\0')
		return (res);
	while (res[i] != '\0')
	{
		j = 0;
		if (res[i + j] == s2[j])
		{
			while (res[i + j] == s2[j] && s2[j] != '\0')
				j++;
			if (s2[j] == '\0')
				return (res + i);
		}
		i++;
	}
	return (NULL);
}
