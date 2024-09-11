/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:20:07 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/23 14:27:10 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_swap_a_b(t_DLIST **stack)
{
	t_DLIST	*last;
	t_DLIST	*prev;
	t_DLIST	*prev_prev;

	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
	last = ft_last_node(*stack);
	prev = last->prev;
	if (prev == *stack)
	{
		last->next = *stack;
		last->prev = NULL;
		(*stack)->prev = last;
		(*stack)->next = NULL;
		*stack = last;
		return ;
	}
	prev_prev = prev->prev;
	prev_prev->next = last;
	last->prev = prev_prev;
	last->next = prev;
	prev->prev = last;
	prev->next = NULL;
}

void	ft_push(t_DLIST **to_push, t_DLIST **dest)
{
	t_DLIST	*last;

	if (!(*to_push))
		return ;
	last = ft_last_node(*to_push);
	if (!last->prev)
		*to_push = NULL;
	else
		last->prev->next = NULL;
	ft_add_back_dl(dest, last->content);
	free(last);
}

void	ft_rotate(t_DLIST **stack)
{
	t_DLIST	*last;
	t_DLIST	*first;

	if (!(*stack))
		return ;
	if (!(*stack)->next)
		return ;
	last = ft_last_node(*stack);
	first = ft_first_node(*stack);
	first->prev = last;
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	*stack = last;
}

void	ft_reverse_rotate(t_DLIST **stack)
{
	t_DLIST	*last;
	t_DLIST	*first;
	t_DLIST	*tempo;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = ft_last_node(*stack);
	if (!last)
		return ;
	first = *stack;
	tempo = first->next;
	last->next = first;
	first->prev = last;
	tempo->prev = NULL;
	first->next = NULL;
	*stack = tempo;
}
