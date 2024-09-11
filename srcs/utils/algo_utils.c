/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:08:58 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/23 16:21:20 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

// Find the right position for a value if the value != min or max
int	easy_case(t_DLIST *stack, int value)
{
	t_DLIST	*node;
	t_DLIST	*next;
	t_NK	nk;
	int		inter;

	inter = 2147483647;
	nk.i = 1;
	nk.j = 0;
	node = ft_last_node(stack);
	next = node->prev;
	while (node)
	{
		if (!next)
			next = stack;
		if ((node->content > value && value > next->content)
			&& ((node->content - next->content) < inter))
		{
			nk.j = nk.i;
			inter = node->content - next->content;
		}
		node = node->prev;
		next = next->prev;
		nk.i++;
	}
	return (nk.j);
}

//Find the index of the node we need to insert
int	find_place(t_DLIST *stack, t_DLIST *node)
{
	int	i;

	i = 0;
	if (node->content > what_max(stack))
	{
		i = find_min(stack);
	}
	else if (node->content < what_min(stack))
	{
		i = find_min(stack);
	}
	else
		i = easy_case(stack, node->content);
	return (i);
}

//Give the number of rotation we have to do to get to an index
int	index_to_moov(t_DLIST *stack, t_DLIST *node)
{
	int	len;
	int	i;
	int	result;

	i = 0;
	result = 0;
	len = len_stack(stack);
	i = find_place(stack, node);
	if (i > len / 2)
		result = i - len;
	else
	{
		result = i;
	}
	return (result);
}

int	bring_it_to_top(t_DLIST *stack, t_DLIST *node)
{
	t_DLIST	*temp;
	int		i;
	int		len;
	int		result;

	result = 0;
	len = len_stack(stack);
	i = 0;
	temp = ft_last_node(stack);
	while (temp && (temp != node))
	{
		temp = temp->prev;
		i++;
	}
	if (i > len / 2)
		result = i - len;
	else
		result = i;
	return (result);
}

// This function place the min element of the stack at the botton
// of the stack
void	in_order(t_DLIST **stack)
{
	int	i;

	i = find_min(*stack);
	if (i < len_stack(*stack) / 2)
	{
		while ((*stack)->content != what_min(*stack))
		{
			ft_rotate(stack);
			ft_printf("rb\n");
			i--;
		}
	}
	else
	{
		while ((*stack)->content != what_min(*stack))
		{
			ft_reverse_rotate(stack);
			ft_printf("rrb\n");
			i--;
		}
	}
}
