/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:27:26 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/27 01:38:42 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	sort_3_bis(t_DLIST **stack, int fst, int scd, int trd)
{
	if (fst > scd && scd < trd && fst > trd)
	{
		ft_rotate(stack);
		ft_printf("ra\n");
	}
	else if (fst < scd && scd > trd && fst < trd)
	{
		ft_swap_a_b(stack);
		ft_rotate(stack);
		ft_printf("sa\nra\n");
	}
	else if (fst < scd && scd > trd && fst > trd)
	{
		ft_reverse_rotate(stack);
		ft_printf("rra\n");
	}
}

// The optimal way to sort 3 numbers
void	sort_3(t_DLIST **stackA)
{
	t_DLIST	*node;
	int		fst;
	int		scd;
	int		trd;

	node = ft_last_node(*stackA);
	fst = node->content;
	scd = node->prev->content;
	trd = node->prev->prev->content;
	if (fst > scd && scd > trd)
	{
		ft_swap_a_b(stackA);
		ft_reverse_rotate(stackA);
		ft_printf("sa\nrra\n");
	}
	else if (fst > scd && scd < trd && fst < trd)
	{
		ft_swap_a_b(stackA);
		ft_printf("sa\n");
	}
	else
		sort_3_bis(stackA, fst, scd, trd);
}

// The optimal way to sort 4 numbers
void	sort_4(t_DLIST **sA, t_DLIST **sB)
{
	int	i;

	i = find_min(*sA);
	if (i > len_stack(*sA) / 2)
	{
		while (ft_last_node(*sA)->content != what_min(*sA))
		{
			ft_reverse_rotate(sA);
			ft_printf("rra\n");
		}
	}
	else
	{
		while (ft_last_node(*sA)->content != what_min(*sA))
		{
			ft_rotate(sA);
			ft_printf("ra\n");
		}
	}
	ft_push(sA, sB);
	ft_printf("pb\n");
	sort_3(sA);
	ft_push(sB, sA);
	ft_printf("pa\n");
}

// The optimal way to sort 5 numbers
void	sort_5(t_DLIST **sA, t_DLIST **sB)
{
	if (find_min(*sA) > len_stack(*sA) / 2)
	{
		while (ft_last_node(*sA)->content != what_min(*sA))
		{
			ft_reverse_rotate(sA);
			ft_printf("rra\n");
		}
	}
	else
	{
		while (ft_last_node(*sA)->content != what_min(*sA))
		{
			ft_rotate(sA);
			ft_printf("ra\n");
		}
	}
	ft_push(sA, sB);
	ft_printf("pb\n");
	sort_4(sA, sB);
	ft_push(sB, sA);
	ft_printf("pa\n");
	ft_push(sB, sA);
	ft_printf("pa\n");
}

void	small_sort(t_DLIST **stack_A, t_DLIST **stack_B)
{
	if (len_stack(*stack_A) == 3)
		sort_3(stack_A);
	else if (len_stack(*stack_A) == 4)
		sort_4(stack_A, stack_B);
	else if (len_stack(*stack_A) == 5)
		sort_5(stack_A, stack_B);
	else
	{
		if (len_stack(*stack_A) == 1)
			return ;
		else
		{
			if ((*stack_A)->content < (*stack_A)->next->content)
			{
				ft_swap_a_b(stack_A);
				ft_printf("sa\n");
			}
		}
	}
}
