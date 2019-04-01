/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <jnabet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:07:10 by jnabet            #+#    #+#             */
/*   Updated: 2019/03/25 15:08:17 by lboit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read_av(char *av)
{
	char	fd;
	int		l;
	char	*str;
	char	*line;

	fd = open(av, O_RDONLY);
	l = 0;
	line = 0;
	if (!(str = tet_ok(fd, line, l)))
		return (0);
	close(fd);
	return (str);
}

int		fillit(char **str, char ***tmp)
{
	char	*res;
	int		m;
	int		i;

	m = 1;
	i = 0;
	while (tmp[i] != 0)
		i++;
	res = map(m);
	while (resolve(res, *tmp, ft_nb_tet(*str), 0) == -1)
	{
		m++;
		free(res);
		res = NULL;
		res = map(m);
	}
	ft_putstr(res);
	free(res);
	return (0);
}

int		main(int ac, char **av)
{
	char	*str;
	char	**tmp;
	int		i;

	i = 0;
	if (ac != 2)
	{
		ft_putendl("usage : ./fillit [filename]");
		return (0);
	}
	av++;
	if (!(str = ft_read_av(*av)))
		return (0);
	if (!(tmp = ft_strsplit(str, ' ')))
	{
		free(str);
		ft_putendl("error");
		return (0);
	}
	fillit(&str, &tmp);
	while (tmp[i])
		ft_strdel(&tmp[i++]);
	free(tmp);
	free(str);
	return (0);
}
