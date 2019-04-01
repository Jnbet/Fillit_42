/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:44:23 by jnabet            #+#    #+#             */
/*   Updated: 2018/11/20 10:49:30 by jnabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned int		i;

	d = (unsigned char*)dest;
	s = (const unsigned char*)src;
	i = 0;
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
		return (d);
	}
	else
	{
		while (n)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
		return (d);
	}
}
