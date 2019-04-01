/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:45:03 by jnabet            #+#    #+#             */
/*   Updated: 2018/11/21 15:45:43 by jnabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	size_dest;
	unsigned int	size_src;

	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	if (size <= size_dest)
		return (size_src + size);
	ft_strncat(dest, src, (size - size_dest - 1));
	return (size_dest + size_src);
}
