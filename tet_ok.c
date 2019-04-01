/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_ok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboit <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:50:44 by lboit             #+#    #+#             */
/*   Updated: 2019/03/25 17:13:11 by lboit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	make(char **str, char **tmp, char *line)
{
	if (*str == 0)
		*tmp = ft_strdup(line);
	else
		*tmp = ft_strjoinfree(*str, line);
	*str = ft_strjoinfree(*tmp, "\n");
}

char	*tet_ok(int fd, char *line, int l)
{
	int		ret;
	char	*str;
	char	*tmp;
	char	*res;

	str = 0;
	res = 0;
	tmp = 0;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		l++;
		if (l % 5 != 0)
			make(&str, &tmp, line);
		if (l % 5 == 0 && line[0] != '\0')
			return (error(res, &str));
		if (l % 5 == 4)
		{
			if (!(res = fill_res(res, &str)))
				return (NULL);
		}
		free(line);
	}
	if (!(ft_error2(l)))
		return (error(res, &str));
	return (res);
}
