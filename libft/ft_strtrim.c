/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:28:44 by jnabet            #+#    #+#             */
/*   Updated: 2018/11/22 14:25:42 by jnabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char const	*res;

	if (s)
	{
		while (*s == ' ' || *s == '\t' || *s == '\n')
			s++;
		if (*s == '\0')
			return (ft_strnew(0));
		res = s + ft_strlen(s) - 1;
		while (*res == ' ' || *res == '\t' || *res == '\n')
			res--;
		return (ft_strsub(s, 0, res - s + 1));
	}
	return (NULL);
}
