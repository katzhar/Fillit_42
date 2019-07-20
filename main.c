/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aernie <aernie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:59:04 by aernie            #+#    #+#             */
/*   Updated: 2019/07/20 19:20:11 by aernie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int							main(int argc, char **argv)
{
	static t_tet			*first;
    int						fd;
	int						res;
	char					file[BUFF_SIZE];

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		res = read(fd, file, BUFF_SIZE);
		file[res] = '\0';
		res = tet_read(file, res, &first);
		if (res == 0)
		{
			delete_lst(&first);
			write(1, "error\n", 6);
			return (1);
		}
		printf("%d\n", res);
		main_move(&first, (res + 1) / 21);
	}
	else
		write(1, "usage: ./fillit target_filename\n", 32);
	return (0);
}
