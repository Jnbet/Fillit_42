/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:56:59 by jnabet            #+#    #+#             */
/*   Updated: 2018/11/29 10:47:46 by jnabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_nbwords(char const *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	size;

	i = 0;
	words = 0;
	size = ft_strlen(s);
	while (i < size)
	{
		if (i == 0 && s[i] != c)
			words++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			words++;
		i++;
	}
	return (words);
}

static char	**ft_word(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			j = i;
			while (s[i] && s[i] != c)
				i++;
			tab[k] = ft_strsub(s, j, i - j);
			k++;
			tab[k] = 0;
		}
	}
	tab[k] = 0;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;

	if (s)
	{
		if (!(res = (char**)malloc(sizeof(char*) * (ft_nbwords(s, c) + 1))))
			return (NULL);
		ft_bzero(res, (ft_nbwords(s, c) + 1));
		return (ft_word(s, c, res));
	}
	return (NULL);
}
