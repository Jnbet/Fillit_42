/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <jnabet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:40:40 by jnabet            #+#    #+#             */
/*   Updated: 2019/03/01 18:45:48 by jnabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*move(char *str, int mv)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			str[i - mv] = '#';
			str[i] = '.';
		}
		i++;
	}
	return (str);
}

char	*move_left(char *str)
{
	int i;
	int mv;

	i = 0;
	mv = 0;
	while (str[i])
	{
		if (str[1] == '#' || str[6] == '#' || str[11] == '#' || str[16] == '#')
			mv = 1;
		else if (str[2] == '#' || str[7] == '#' ||
				str[12] == '#' || str[17] == '#')
			mv = 2;
		else if (str[3] == '#' || str[8] == '#' ||
				str[13] == '#' || str[18] == '#')
			mv = 3;
		i++;
	}
	str = move(str, mv);
	return (str);
}

char	*move_up(char *str)
{
	int i;
	int mv;

	i = 0;
	mv = 0;
	while (str[i])
	{
		if (str[5] == '#' || str[6] == '#' || str[7] == '#' || str[8] == '#')
			mv = 5;
		else if (str[10] == '#' || str[11] == '#' ||
				str[12] == '#' || str[13] == '#')
			mv = 10;
		else if (str[15] == '#' || str[16] == '#' ||
				str[17] == '#' || str[18] == '#')
			mv = 15;
		i++;
	}
	str = move(str, mv);
	return (str);
}

char	*move_main(char *str)
{
	int	i;
	int left;
	int up;

	ft_set(&i, &left, &up);
	while (str[i++])
	{
		if (str[0] == '#' || str[1] == '#' || str[2] == '#' || str[3] == '#')
			up = 1;
		if (str[0] == '#' || str[5] == '#' || str[10] == '#' || str[15] == '#')
			left = 1;
	}
	if (left == 1 && up == 1)
		return (str);
	if (left == 0 && up == 1)
		str = move_left(str);
	if (left == 1 && up == 0)
		str = move_up(str);
	if (left == 0 && up == 0)
	{
		str = move_up(str);
		str = move_left(str);
	}
	return (str);
}
