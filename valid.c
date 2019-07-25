/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aernie <aernie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:29:50 by mannette          #+#    #+#             */
/*   Updated: 2019/07/25 14:48:50 by aernie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					connect(char *str)
{
	int i;
	int connect;

	i = 0;
	connect = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i + 1 < 21 && str[i + 1] == '#')
				connect++;
			if (i - 1 >= 0 && str[i - 1] == '#')
				connect++;
			if (i + 5 < 21 && str[i + 5] == '#')
				connect++;
			if (i - 5 >= 0 && str[i - 5] == '#')
				connect++;
		}
		i++;
	}
	return (connect);
}

int					valid(int len, char *s, t_tet **first)
{
	int		i;
	int		count;
	int		con;
	t_tet	*lst;

	lst = create_lst(first, len);
	i = -1;
	count = 0;
	con = 0;
	while (++i < 20)
	{
		if (i % 5 == 4 && s[i] != '\n')
			return (0);
		else if (i % 5 != 4)
		{
			if (s[i] != '.' && s[i] != '#')
				return (0);
			if (s[i] == '#' && count < 4)
			{
				coordinate(&lst, i, count++);
			}
		}
	}
	con = connect(s);
	return ((count != 4 || (con != 6 && con != 8)) ? 0 : first_steps(&lst));
}

int					tet_read(char *s, int len, t_tet **first)
{
	char	*tet;
	int		i;

	i = 0;
	if (len < 20)
		return (0);
	while (i < len)
	{
		if (!(tet = ft_strsub(s, i, 20)))
			return (0);
		if (valid(i, tet, first) == 0)
		{
			free(tet);
			return (0);
		}
		free(tet);
		i += 20;
		if (i < len && s[i] != '\n')
			return (0);
		else if (len - i < 20 && len - i > 0)
			return (0);
		i++;
	}
	return (len);
}
