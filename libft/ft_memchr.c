/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:31:50 by jnabet            #+#    #+#             */
/*   Updated: 2018/11/28 12:34:02 by jnabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	find;
	unsigned char	*str;

	find = (unsigned char)c;
	str = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == find)
			return (str + i);
		i++;
	}
	return (NULL);
}
