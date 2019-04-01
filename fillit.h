/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <jnabet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:07:10 by jnabet            #+#    #+#             */
/*   Updated: 2019/03/25 15:57:27 by lboit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		checktet(char *str);
char	*tet_ok(int fd, char *line, int l);
char	*move_main(char *str);
int		ft_sqr_min(int nb_tet);
int		resolve(char *res, char **tmp, int nb_tet, int tet);
char	*map(int nb_tet);
int		ft_nb_tet(char *str);
char	*map(int nb_tet);
int		ft_fillit(char *map, char *str, int start, int tet);
void	ft_set(int *tet, int *len, int *height);
char	*ft_strjoinfree(char *s1, char *s2);
int		ft_error2(int l);
char	*error(char *res, char **str);
char	*fill_res(char *res, char **str);
int		checkfile(char *str);

#endif
