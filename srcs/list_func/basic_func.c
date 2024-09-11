/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:52:55 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/22 15:08:26 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_DLIST	*ft_last_node(t_DLIST *node)
{
	t_DLIST	*temp;

	if (!node)
		return (NULL);
	temp = node;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

t_DLIST	*ft_first_node(t_DLIST *node)
{
	t_DLIST	*temp;

	if (!node)
		return (NULL);
	temp = node;
	while (temp->prev)
	{
		temp = temp->prev;
	}
	return (temp);
}

void	ft_add_back_dl(t_DLIST **list, int content)
{
	t_DLIST	*new_elem;
	t_DLIST	*last;

	new_elem = malloc(sizeof(t_DLIST));
	if (!new_elem)
		return ;
	new_elem->content = content;
	new_elem->next = NULL;
	if (!(*list))
	{
		*list = new_elem;
		new_elem->prev = NULL;
	}
	else
	{
		last = ft_last_node(*list);
		last->next = new_elem;
		new_elem->prev = last;
	}
}

void	ft_insert_node(t_DLIST **dest, t_DLIST *node)
{
	t_DLIST	*temp;

	if (!dest || !node)
		return ;
	if (*dest == NULL)
	{
		*dest = node;
		node->prev = NULL;
		node->next = NULL;
		return ;
	}
	temp = ft_last_node(*dest);
	temp->next = node;
	node->prev = temp;
	node->next = NULL;
}

void	ft_free_chain(t_DLIST *stack)
{
	t_DLIST	*temp;

	if (!stack)
		return ;
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
