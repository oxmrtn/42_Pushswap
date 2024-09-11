/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:55:30 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/24 16:48:49 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

// The func return the maximum value in Stack
int	what_max(t_DLIST *stack)
{
	t_DLIST	*temp;
	int		max;

	temp = stack;
	max = -2147483647;
	while (temp)
	{
		if (temp->content > max)
			max = temp->content;
		temp = temp->next;
	}
	return (max);
}

// The func return the minimum value in Stack
int	what_min(t_DLIST *stack)
{
	t_DLIST	*temp;
	int		min;

	temp = stack;
	min = 2147483647;
	while (temp)
	{
		if (temp->content < min)
			min = temp->content;
		temp = temp->next;
	}
	return (min);
}

//The func return the index of the minimum value
int	find_min(t_DLIST *stack)
{
	t_DLIST	*temp;
	int		min;
	int		i;
	int		j;

	min = 2147483647;
	i = 1;
	j = 0;
	temp = ft_last_node(stack);
	while (temp)
	{
		if (min > temp->content)
		{
			min = temp->content;
			j = i;
		}
		temp = temp->prev;
		i++;
	}
	return (j);
}

//The func return the index of the maximum value
int	find_max(t_DLIST *stack)
{
	t_DLIST	*temp;
	int		max;
	int		i;
	int		j;

	max = -2147483647;
	i = 1;
	j = 0;
	temp = ft_last_node(stack);
	while (temp)
	{
		if (max < temp->content)
		{
			max = temp->content;
			j = i;
		}
		temp = temp->prev;
		i++;
	}
	return (j);
}
