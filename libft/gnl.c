/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brobson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:22:39 by brobson           #+#    #+#             */
/*   Updated: 2019/03/22 15:51:39 by lboit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_error(const int fd, char **str, char **line)
{
	if (fd == -1 || line == NULL)
		return (-1);
	if (!*str)
	{
		if (!(*str = ft_strnew(BUFF_SIZE)))
			return (-1);
	}
	return (0);
}

int		ft_readline(const int fd, char **str, int *b_read)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while ((*b_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[*b_read] = '\0';
		tmp = ft_strjoin(*str, buf);
		free(*str);
		*str = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (*b_read == -1)
		return (-1);
	return (0);
}

void	ft_filling(char **line, char **str, int i)
{
	char	*tmp;

	*line = ft_strsub(*str, 0, i);
	tmp = ft_strdup(*str + i + 1);
	free(*str);
	*str = tmp;
}

int		get_next_line(const int fd, char **line)
{
	static char			*str = NULL;
	int					b_read;
	int					i;

	i = 0;
	if (ft_error(fd, &str, line) == -1)
		return (-1);
	if (ft_readline(fd, &str, &b_read) == -1)
		return (-1);
	if (b_read == 0 && ft_strcmp(str, "") == 0)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		ft_filling(line, &str, i);
		if (str[0] == '\0')
			ft_strdel(&str);
	}
	else if (str[i] == '\0')
	{
		*line = ft_strdup(str);
		ft_strdel(&str);
	}
	return (1);
}
