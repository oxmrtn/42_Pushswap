/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:46:12 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/25 15:54:32 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

// Return len of a stack
int	len_stack(t_DLIST *node)
{
	t_DLIST	*temp;
	int		i;

	i = 1;
	if (!node)
		return (0);
	temp = node;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

// Free a char**
void	free_tab(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// Return 1 if nbr is not a int
int	is_int(long nbr)
{
	return (nbr > 2147483647 || nbr < -2147483648);
}

int	is_sorted(t_DLIST *stack_A, t_DLIST *stack_B)
{
	t_DLIST	*node;

	if (stack_B)
		return (0);
	if (!stack_A || !stack_A->next)
		return (1);
	node = stack_A->next;
	while (node)
	{
		if (stack_A->content < node->content)
			return (0);
		stack_A = node;
		node = node->next;
	}
	return (1);
}
