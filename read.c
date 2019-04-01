/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <jnabet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:50:28 by jnabet            #+#    #+#             */
/*   Updated: 2019/03/25 17:15:31 by lboit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checkfile(char *str)
{
	if (checktet(str) == 1)
		return (1);
	if (checktet(str) == 0)
		return (0);
	return (0);
}

int		ft_error2(int l)
{
	if (l < 4 || l > 129)
		return (0);
	if ((((l + 1) * 4) % 5) != 0)
		return (0);
	return (1);
}

char	*error(char *res, char **str)
{
	if (str)
		ft_strdel(str);
	if (res)
		free(res);
	ft_putendl("error");
	return (NULL);
}

char	*fill_res(char *res, char **str)
{
	char	*tmp;

	tmp = 0;
	if (checkfile(*str) == 1)
	{
		if (res == 0)
		{
			if (!(tmp = ft_strdup(*str)))
				return (error(res, str));
		}
		else
		{
			if (!(tmp = ft_strjoinfree(res, *str)))
				return (error(res, str));
		}
		if (!(res = ft_strjoinfree(tmp, " ")))
			return (error(res, str));
	}
	else
		return (error(res, str));
	free(*str);
	*str = 0;
	return (res);
}
