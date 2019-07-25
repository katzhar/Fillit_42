/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aernie <aernie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:48:26 by aernie            #+#    #+#             */
/*   Updated: 2019/07/25 17:22:07 by aernie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void					delete_lst(t_tet **first)
{
	t_tet *lst;

	if (first == NULL)
		return ;
	while (*first)
	{
		lst = *first;
		(*first) = (*first)->next;
		free(lst);
	}
}

t_tet					*new_lst(int symb)
{
	static t_tet *lst;

	if (!(lst = (t_tet*)malloc(sizeof(t_tet))))
		return (NULL);
	lst->last_x = 0;
	lst->last_y = 0;
	lst->prev = NULL;
	lst->next = NULL;
	lst->letter = symb;
	return (lst);
}

t_tet					*create_lst(t_tet **first, int i)
{
	t_tet	*lst;
	t_tet	*new_elem;
	int		k;

	if (!(*first))
		return (*first = new_lst(65));
	k = 1;
	lst = *first;
	while (i > 20)
	{
		if (lst->letter == (k + 65))
			return (lst);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
		k++;
		i -= 20;
	}
	new_elem = new_lst(k + 65);
	new_elem->prev = lst;
	lst->next = new_elem;
	return (new_elem);
}
