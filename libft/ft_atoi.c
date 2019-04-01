/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:42:38 by jnabet            #+#    #+#             */
/*   Updated: 2018/11/21 12:06:54 by jnabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int cpt;
	int resultat;
	int signe;

	resultat = 0;
	signe = 1;
	cpt = 0;
	while (str[cpt] == ' ' || str[cpt] == '\t' || str[cpt] == '\v' ||
			str[cpt] == '\r' || str[cpt] == '\f' || str[cpt] == '\n')
		cpt++;
	if (str[cpt] == '-')
	{
		cpt++;
		signe = -1;
	}
	else if (str[cpt] == '+')
		cpt++;
	while (str[cpt] >= '0' && str[cpt] <= '9')
	{
		resultat = resultat * 10;
		resultat = resultat + (str[cpt] - 48);
		cpt++;
	}
	return (resultat * signe);
}
