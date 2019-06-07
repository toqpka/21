/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:50:16 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/04/01 22:00:39 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 600

typedef struct s_etrim	t_etrim;

struct			s_etrim
{
	int			width;
	int			height;
	char		letter;
	int			tab[16];
};

typedef struct s_node	t_node;

struct			s_node
{
	int			l;
	int			r;
	int			u;
	int			d;
	int			c;
	int			num_elem;
	char		letter;
};

/*
** Read_file && Check_Valid
*/
int				ft_check_conection(char *s, int i);
int				main_test(char *str);
int				ft_check_valid(char *str);
int				check_size(char *str);
int				ft_check_conection(char *str, int i);
char			check_valid(char *str);

/*
** Create_t_etrim
*/
int				count_num(char *str);
int				minimum_grid(int num_f);
t_etrim			*create_tet_tabs(char *str);
t_etrim			*create_tetrim(int **tab, int nb_fig);
int				add_figures(t_etrim **t, int num_f, int nb);
int				possible_rows(t_etrim *tet, int numb_fig, int side);
int				check_pos_h(int *tab, int i);
int				check_pos_w(int *tab, int i);

/*
** Create_matrix
*/
char			**cr_mat(t_etrim *tetrimin, int numb_fig,\
					int side, int nb_possib);
void			move_buf_left(t_etrim *tet);
void			move_buf_top(t_etrim *tet);
char			*read_input(char **argv);

/*
** Create_nodes
*/
t_node			*create_link_nodes(char **matrix, int numb_fig,\
					int side, int nb_possible);
void			links_nodes_to_null(t_node *n, int nb_col, int nb_possib);
int				link_r_and_l(t_node *n, int i, int nb_block, int *flag);
void			link_u_and_d(t_node *n, int i, int j);
void			give_letters(t_node **link_nodes, int num_f, int side);

/*
** Solve && Print
*/
void			solve(t_etrim *tetrimin, int num_f, int side);
int				search(t_node *n, int *solv, int k, int side);
void			cover_col(t_node *n, int col);
void			cover_row(t_node *n, int row);
void			uncolver_col(t_node *n, int col);
void			unrowver_row(t_node *n, int row);
char			*create_print(int side);
int				count_r_nodes(t_node *n, int side, int l);
int				find_col_side(t_node *n, int side);

#endif
