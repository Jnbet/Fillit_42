/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:48:06 by jnabet            #+#    #+#             */
/*   Updated: 2018/11/20 11:18:00 by jnabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*i;
	char	*j;

	if (*s2 == '\0')
		return ((char *)s1);
	while (n-- && *s1)
	{
		if (*s1 == *s2)
		{
			i = (char *)s1 + 1;
			j = (char *)s2 + 1;
			while (n-- && *i && *j && *i == *j)
			{
				i++;
				j++;
			}
			if (*j == '\0')
				return ((char *)s1);
		}
		s1++;
	}
	return (NULL);
}
