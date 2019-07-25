/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aernie <aernie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:10:25 by mannette          #+#    #+#             */
/*   Updated: 2019/07/25 17:19:14 by aernie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int			second_steps(t_tet **lst)
{
	int min_y;
	int i;

	min_y = 3;
	i = 0;
	while (i < 4)
	{
		min_y = (min_y > (*lst)->y[i] ? (*lst)->y[i] : min_y);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		(*lst)->y[i] -= min_y;
		i++;
	}
	return (1);
}

int			first_steps(t_tet **lst)
{
	int min_x;
	int i;

	min_x = 3;
	i = 0;
	while (i < 4)
	{
		min_x = (min_x > (*lst)->x[i] ? (*lst)->x[i] : min_x);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		(*lst)->x[i] -= min_x;
		i++;
	}
	return (second_steps(lst));
}

int			coordinate(t_tet **lst, int i, int count)
{
	if (i < 4)
	{
		(*lst)->x[count] = i;
		(*lst)->y[count] = 0;
	}
	else if (i > 4 && i < 9)
	{
		(*lst)->x[count] = i - 5;
		(*lst)->y[count] = 1;
	}
	else if (i > 9 && i < 14)
	{
		(*lst)->x[count] = i - 10;
		(*lst)->y[count] = 2;
	}
	else if (i > 14 && i < 19)
	{
		(*lst)->x[count] = i - 15;
		(*lst)->y[count] = 3;
	}
	return (0);
}
