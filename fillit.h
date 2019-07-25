/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aernie <aernie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:28:10 by aernie            #+#    #+#             */
/*   Updated: 2019/07/25 13:51:12 by aernie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 547
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_tet
{
	int				x[4];
	int				y[4];
	int				last_x;
	int				last_y;
	char			letter;
	struct s_tet	*next;
	struct s_tet	*prev;
}					t_tet;

/*
** validation
*/
int					tet_read(char *s, int len, t_tet **first);
int					valid(int len, char *s, t_tet **first);
int					connect(char *str);

/*
** coordinate
*/
int					coordinate(t_tet **lst, int i, int count);
int					first_steps(t_tet **lst);
int					second_steps(t_tet **lst);

/*
** list
*/
t_tet				*create_lst(t_tet **first, int i);
t_tet				*new_lst(int symb);
void				delete_lst(t_tet **first);

/*
** move
*/
int					main_move(t_tet **first, int line);
void				move(t_tet **lst, char ***map, int line);
int					check(t_tet **lst, char **map, int line);
void				zero_y(t_tet **lst);

/*
** map
*/
char				create_map(int line, char ***map);
void				tet_on_the_map(t_tet **lst, char ***map);
void				clear_map(t_tet **lst, char ***map);
void				delete_map(char ***map);

#endif
