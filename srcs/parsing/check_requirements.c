/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_requirements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:37:59 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/28 18:07:46 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	no_duplicate(long content, t_DLIST *stack)
{
	while (stack)
	{
		if (stack->content == (int)content)
			return (1);
		stack = stack->next;
	}
	return (0);
}

// This function check if the list only contains int
int	ft_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || (str[i] == ' ')))
		{
			if (!((str[i] == '+' || str[i] == '-' ) && ft_isdigit(str[i + 1])))
				return (1);
			else if (i > 0 && ((str[i] == '+' || str[i] == '-')
					&& ft_isdigit(str[i - 1])))
				return (1);
		}
		i++;
	}
	return (0);
}

t_DLIST	*create_list_extends(char **buffer, char *str, t_DLIST *list)
{
	ft_putstr_fd("Error\n", 2);
	ft_free_chain(list);
	free_tab(buffer);
	free(str);
	return (NULL);
}

t_DLIST	*create_list(char *str)
{
	char	**buffer;
	int		i;
	long	temp;
	t_DLIST	*list;

	list = NULL;
	temp = 0;
	i = 0;
	buffer = ft_split(str, ' ');
	if (!buffer)
		return (NULL);
	while (buffer[i + 1])
		i++;
	while (i >= 0)
	{
		temp = ft_atoi(buffer[i]);
		if (is_int(temp) || no_duplicate(temp, list))
			return (create_list_extends(buffer, str, list));
		ft_add_back_dl(&list, temp);
		i--;
	}
	free_tab(buffer);
	free(str);
	return (list);
}

void	print_lsit(t_DLIST *head)
{
	t_DLIST	*node;

	node = ft_last_node(head);
	if (!node)
	{
		ft_printf("\n");
		return ;
	}
	while (node)
	{
		ft_printf("|%d|\n", node->content);
		node = node->prev;
	}
	ft_printf("\n");
}
