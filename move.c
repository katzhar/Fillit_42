/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aernie <aernie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:35:24 by aernie            #+#    #+#             */
/*   Updated: 2019/07/20 18:20:01 by aernie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     main_move(t_tet **first, int line)
{
    t_tet   *lst;
    char    **map;
    int     i;

    i = 0;
    lst = *first;
    line = ft_sqrt(line * 4);
    create_map(line, &map);
    move(&lst, &map, line);
    return(0);
}

int     check(t_tet **lst, char **map, int line)
{
       int i;
       
       i = 0;
       while (i < 4)
       {
           if ((*lst)->x[i] + (*lst)->last_x >= line)
           {
               i = 0;
               (*lst)->last_x = 0;
               (*lst)->last_y++;
           }
            if ((*lst)->y[i] + (*lst)->last_y == line)
                break ;
            if (map[(*lst)->y[i] + (*lst)->last_y][(*lst)->x[i] + (*lst)->last_x] == '.')
                i++;
            else
            {
                i = 0;
                (*lst)->last_x++;
            } 
       }
       return (i == 4 ? 1 : 0);
}

int     move(t_tet **lst, char ***map, int line)
{
    while(lst)
    {
        if (check(lst, *map, line))
        {
            tet_on_the_map(lst, map);
            (*lst) = (*lst)->next;
        }
        else
        {
            if ((*lst)->prev == NULL)
            {
                create_map(++line, map);
                zero_y(lst);
            }
            else
            {
                clear_map(&(*lst)->prev, map);
                (*lst)->last_x = 0;
                (*lst)->last_y = 0;
                (*lst)->prev->last_x++;
                (*lst) = (*lst)->prev;
            }
        }
    }
    return (0);
}

void		zero_y(t_tet **lst)
{
	t_tet				*node;

	node = *lst;
	while (node)
	{
		node->last_y = 0;
		node = node->next;
	}
}
