/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:06:47 by jnabet            #+#    #+#             */
/*   Updated: 2019/01/19 18:58:15 by jnabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	n;

	if (s)
	{
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		n = 0;
		while (n < len)
		{
			str[n] = s[start + n];
			n++;
		}
		str[n] = '\0';
		return (str);
	}
	return (NULL);
}
