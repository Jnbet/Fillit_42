/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:52:36 by jnabet            #+#    #+#             */
/*   Updated: 2018/11/21 16:31:28 by jnabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	if (s)
	{
		size = ft_strlen(s);
		if (!(str = malloc(sizeof(char) * (size + 1))))
			return (NULL);
		while (s[i])
		{
			str[i] = f(s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
