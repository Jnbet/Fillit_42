/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:23:12 by jnabet            #+#    #+#             */
/*   Updated: 2018/11/29 12:38:23 by jnabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*chain;

	if (!(chain = (t_list*)malloc(sizeof(*chain))))
		return (NULL);
	if (content == NULL)
	{
		chain->content = NULL;
		chain->content_size = 0;
	}
	else
	{
		if (!(chain->content = (t_list*)malloc(sizeof(content_size))))
			return (NULL);
		ft_memcpy(chain->content, content, content_size);
		chain->content_size = content_size;
	}
	chain->next = NULL;
	return (chain);
}
