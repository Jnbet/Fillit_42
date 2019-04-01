/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:31:52 by jnabet            #+#    #+#             */
/*   Updated: 2018/11/28 12:37:34 by jnabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dst;
	unsigned char	*str;
	unsigned char	find;

	i = 0;
	str = (unsigned char*)src;
	dst = (unsigned char*)dest;
	find = (unsigned char)c;
	while (i < n)
	{
		dst[i] = str[i];
		i++;
		if (str[i - 1] == find)
			return (dst + i);
	}
	return (NULL);
}
