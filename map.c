/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <jnabet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:02:35 by jnabet            #+#    #+#             */
/*   Updated: 2019/03/22 18:05:00 by lboit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_nb_tet(char *str)
{
	int		i;
	int		nb_tet;

	i = 0;
	nb_tet = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			nb_tet++;
		i++;
	}
	return (nb_tet);
}

int			ft_sqr_min(int nb_tet)
{
	int		sqr_min;
	int		tmp;

	tmp = nb_tet + 2;
	sqr_min = tmp * (tmp - 1);
	return (sqr_min);
}

char		*map(int nb_tet)
{
	int		i;
	int		j;
	int		sqr;
	char	*res;

	i = 0;
	j = 0;
	sqr = ft_sqr_min(nb_tet);
	res = (char*)ft_memalloc(sizeof(char) * (sqr + 1));
	while (i * i + i != sqr)
		i++;
	while (j < sqr)
	{
		if (j != 0 && j % (i + 1) == 0)
			res[j - 1] = '\n';
		res[j] = '.';
		j++;
	}
	res[j - 1] = '\n';
	res[j] = '\0';
	return (res);
}
