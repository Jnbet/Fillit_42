/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <jnabet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:02:35 by jnabet            #+#    #+#             */
/*   Updated: 2019/03/22 18:06:11 by lboit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_line(char *res)
{
	int		i;

	i = 0;
	while (res[i] != '\n')
		i++;
	return (i);
}

int			ft_res_is_ok(char *str, int l)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (str[i] == l + 'A')
			cpt++;
		i++;
	}
	if (cpt == 4)
		return (1);
	else
		return (-1);
}

void		remove_t(char *res, int l)
{
	int		i;
	int		n;

	i = 0;
	n = l + 'A';
	while (res[i])
	{
		if (res[i] == n)
			res[i] = '.';
		i++;
	}
}

int			place(char *res, char *tmp, int r, int l)
{
	int		t;
	int		len;
	int		check;

	t = 0;
	len = ft_line(res);
	check = 0;
	while (tmp[t])
	{
		if (check == 1 && tmp[t] != '#')
		{
			r += len - 4;
			check = 0;
		}
		if (tmp[t++] == '#')
		{
			if (res[r] != '.' || (check == 1 && res[r] == '\n'))
				return (-1);
			check = 1;
			res[r] = l + 'A';
		}
		r++;
	}
	return (ft_res_is_ok(res, l));
}

int			resolve(char *map, char **tmp, int nb_tet, int tet)
{
	int		r;

	r = 0;
	if (tmp[tet] == NULL)
		return (1);
	while (map[r] && tet < nb_tet)
	{
		if (place(map, tmp[tet], r, tet) == 1)
		{
			if (resolve(map, tmp, nb_tet, tet + 1) > 0)
				return (1);
			else
				remove_t(map, tet);
		}
		else
			remove_t(map, tet);
		r++;
	}
	return (-1);
}
