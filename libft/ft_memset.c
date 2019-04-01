/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:18:29 by jnabet            #+#    #+#             */
/*   Updated: 2018/11/14 12:24:07 by jnabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s;
	unsigned char	c2;

	i = 0;
	s = (unsigned char*)str;
	c2 = (unsigned char)c;
	while (i < n)
	{
		s[i] = c2;
		i++;
	}
	return (str);
}
