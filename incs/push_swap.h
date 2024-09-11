/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:46:16 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/27 01:19:10 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/incs/ft_printf.h"

typedef struct t_DLIST
{
	int				content;
	struct t_DLIST	*prev;
	struct t_DLIST	*next;
}				t_DLIST;

typedef struct t_MOOV
{
	char	*buffer;
	int		nmoov;
	t_DLIST	*node;
}			t_MOOV;

typedef struct t_NK
{
	int	i;
	int	j;
}				t_NK;

typedef struct t_DAT
{
	int	count;
	int	count_dest;
	int	nbr_moov;
}				t_DAT;

t_DLIST	*ft_last_node(t_DLIST *node);
t_DLIST	*ft_first_node(t_DLIST *node);
t_DLIST	*create_list(char *str);
t_DAT	calc_moov(t_DLIST *node, t_DLIST *origin, t_DLIST *dest);

int		what_max(t_DLIST *stack);
int		find_max(t_DLIST *stack);
int		what_min(t_DLIST *stack);
int		find_min(t_DLIST *stack);
int		ft_checker(char *str);
int		len_stack(t_DLIST *node);
int		find_place(t_DLIST *stack, t_DLIST *node);
int		index_to_moov(t_DLIST *stack, t_DLIST *node);
int		bring_it_to_top(t_DLIST *stack, t_DLIST *node);
int		no_duplicate(long content, t_DLIST *stack);
int		is_sorted(t_DLIST *stack_A, t_DLIST *stack_B);
int		is_int(long nbr);

void	moov_to_do(int count, int count_dest, char **moov);
void	small_sort(t_DLIST **stack_A, t_DLIST **stack_B);
void	execute_check_moov(char *str, t_DLIST **stackA, t_DLIST **stackB);
void	in_order(t_DLIST **stack);
void	find_best_moov(t_DLIST **stackA, t_DLIST **stackB);
void	ft_add_back_dl(t_DLIST **list, int content);
void	print_lsit(t_DLIST *head);
void	ft_insert_node(t_DLIST **node, t_DLIST *dest);
void	ft_swap_a_b(t_DLIST **stack);
void	ft_push(t_DLIST **to_push, t_DLIST **dest);
void	ft_rotate(t_DLIST **stack);
void	ft_reverse_rotate(t_DLIST **stack);
void	ft_free_chain(t_DLIST *stack);
void	ft_rrr(t_DLIST **stackA, t_DLIST **stackB);
void	ft_rr(t_DLIST **stackA, t_DLIST **stackB);
void	ft_ss(t_DLIST **stackA, t_DLIST **stackB);
void	free_tab(char **str);

#endif