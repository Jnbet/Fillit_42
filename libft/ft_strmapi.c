/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:25:54 by jnabet            #+#    #+#             */
/*   Updated: 2018/11/21 16:32:02 by jnabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	int				size;
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s)
	{
		size = ft_strlen(s);
		if (!(str = malloc(sizeof(char) * (size + 1))))
			return (NULL);
		while (s[i])
		{
			str[i] = f(j, s[i]);
			i++;
			j++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
