/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboit <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:58:41 by lboit             #+#    #+#             */
/*   Updated: 2019/03/22 18:00:08 by lboit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*strcat;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	strcat = (char*)malloc(sizeof(char*) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (strcat == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		strcat[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		strcat[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	strcat[i] = '\0';
	return (strcat);
}
