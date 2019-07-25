/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aernie <aernie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:00:03 by aernie            #+#    #+#             */
/*   Updated: 2019/07/25 17:22:01 by aernie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		create_map(int line, char ***map)
{
	int i;

	i = 0;
	*map = (char **)malloc(sizeof(char *) * (line + 1));
	(*map)[line] = NULL;
	while (i < line)
	{
		(*map)[i] = (char *)malloc(sizeof(char) * line);
		(*map)[i][line] = '\0';
		ft_memset((*map)[i], '.', line);
		i++;
	}
	return (0);
}

void		tet_on_the_map(t_tet **lst, char ***map)
{
	short int k;

	k = 0;
	while (k <= 3)
	{
		(*map)[(*lst)->y[k] + (*lst)->last_y]
		[(*lst)->x[k] + (*lst)->last_x] = (*lst)->letter;
		k++;
	}
}

void		clear_map(t_tet **lst, char ***map)
{
	int i;

	i = 0;
	while (i < 4)
	{
		(*map)[(*lst)->y[i] + (*lst)->last_y]
		[(*lst)->x[i] + (*lst)->last_x] = '.';
		i++;
	}
}

void		delete_map(char ***map)
{
	int i;

	i = 0;
	while ((*map)[i])
		i++;
	while (i >= 0)
	{
		free((*map)[i]);
		(*map)[i] = NULL;
		i--;
	}
	free(*map);
	*map = NULL;
}
