/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <jnabet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:02:53 by jnabet            #+#    #+#             */
/*   Updated: 2019/03/02 16:45:08 by jnabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_set(int *tet, int *len, int *height)
{
	*tet = 0;
	*len = 0;
	*height = 0;
}

static int	checksize(char *str, int i)
{
	int		tet;
	int		len;
	int		height;

	ft_set(&tet, &len, &height);
	while (str[i])
	{
		if (str[i] == '.' || str[i] == '#')
			len++;
		if (str[i] == '#')
			tet++;
		if (str[i] == '\n')
		{
			if (len != 4 || i > 19)
				return (0);
			height++;
			len = 0;
		}
		if (str[i + 1] == '\0' && len == 4)
			height++;
		i++;
	}
	if (height != 4 || tet != 4)
		return (0);
	return (1);
}

static int	checkpattern(char *str, int i)
{
	int		tet;

	tet = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				tet++;
			if (str[i + 5] == '#')
				tet++;
			if (str[i - 1] == '#')
				tet++;
			if (str[i - 5] == '#')
				tet++;
		}
		i++;
	}
	if (tet >= 6 && i == 20)
		return (1);
	return (0);
}

int			checktet(char *str)
{
	if (checksize(str, 0) == 1 && checkpattern(str, 0) == 1)
	{
		str = move_main(str);
		return (1);
	}
	return (0);
}
