/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:27:57 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/24 17:33:48 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libs/ft_printf/ft_printf.h"
# include "./libs/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

// ------------------------ CLISTS ------------------------
typedef struct s_clist
{
	int				n;
	int				i;
	struct s_clist	*next;
}					t_clist;
t_clist	*clst_newnode(int n);
int		clst_size(t_clist *lst);
t_clist	*clst_last(t_clist *lst);
void	clst_append(t_clist **lst, t_clist *node);
void	clst_clear(t_clist **lst);

// ------------------------ CLISTS MOVES ------------------------
void	clst_pop_push(t_clist **src, t_clist **dst, char lst_name);
void	clst_swap(t_clist **lst, char lst_name);
void	clst_d_swap(t_clist **a, t_clist **b);
void	clst_rotate(t_clist **lst, char lst_name);
void	clst_d_rotate(t_clist **a, t_clist **b);
void	clst_rev_rotate(t_clist **lst, char lst_name);
void	clst_dr_rotate(t_clist **a, t_clist **b);

// ------------------------ VALIDATION ------------------------
int		is_valid_argc(int argc);
int		is_valid_argv(char *argv, t_clist *lst);
long	ft_atol(char *str);

// ------------------------ INDEXING ------------------------
void	set_indexes(t_clist **a);

// ------------------------ SORTING ------------------------
void	sort_two(t_clist **a);
void	sort_three(t_clist **a);
void	sort_five(t_clist **a, t_clist **b);
void	sort_six_and_more(t_clist **a, t_clist **b);
void	insertion_sort(t_clist **a, t_clist **b);

// ------------------------ SORTING UTILS ------------------------
int		is_sorted(t_clist *lst);
int		is_rev_sorted(t_clist *lst);
t_clist	*get_biggest_node(t_clist **lst);
t_clist	*get_smallest_node(t_clist **lst);
int		get_dist_upward(int n, t_clist *lst);
int		get_dist_downward(int n, t_clist *lst);
int		move_to_top(t_clist *node, t_clist **lst, char lst_name);
int		move_to_top_best_rotation(t_clist *node, t_clist **lst, char lst_name);

// ------------------------ BITWISE ------------------------
void	print_bits(int n);
int		highest_set(int n);
int		is_set(int n, int i);

// ------------------------ UTILS ------------------------
void	print_bits(int n);
void	free_double_pointer(char **s);
void	clst_print(t_clist *lst, char lst_name);

#endif
