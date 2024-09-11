/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moov.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:41:19 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/27 01:19:34 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

// Just an other part of execute_moov
void	execute_moov_bis(char **moov, int *i, t_DLIST **sA, t_DLIST **sB)
{
	if (!ft_strncmp(moov[*i], "pb", ft_strlen(moov[*i])))
		ft_push(sA, sB);
	else if (!ft_strncmp(moov[*i], "pa", ft_strlen(moov[*i])))
		ft_push(sB, sA);
	else if (!ft_strncmp(moov[*i], "rr", ft_strlen(moov[*i])))
		ft_rr(sA, sB);
	else if (!ft_strncmp(moov[*i], "rrr", ft_strlen(moov[*i])))
		ft_rrr(sA, sB);
	else if (!ft_strncmp(moov[*i], "ra", ft_strlen(moov[*i])))
		ft_rotate(sA);
	else if (!ft_strncmp(moov[*i], "rra", ft_strlen(moov[*i])))
		ft_reverse_rotate(sA);
	else if (!ft_strncmp(moov[*i], "rb", ft_strlen(moov[*i])))
		ft_rotate(sB);
	else if (!ft_strncmp(moov[*i], "rrb", ft_strlen(moov[*i])))
		ft_reverse_rotate(sB);
	ft_printf("%s\n", moov[*i]);
	free(moov[*i]);
	(*i)++;
}

//This function execute the list of moov in str
void	execute_moov(char *str, t_DLIST **stackA, t_DLIST **stackB)
{
	char	**moov;
	int		i;

	i = 0;
	moov = ft_split(str, ' ');
	if (!moov)
		return ;
	while (moov[i])
	{
		execute_moov_bis(moov, &i, stackA, stackB);
	}
	free(moov);
}

// Just an other part of find_best_moov
void	find_best_moov_bis(char *buffer, t_DLIST **stackA, t_DLIST **stackB)
{
	execute_moov(buffer, stackA, stackB);
	if (buffer)
		free(buffer);
}

// This function test every moves for the differents nodes and execute 
// the best option
void	find_best_moov(t_DLIST **stackA, t_DLIST **stackB)
{
	t_DAT	res;
	t_DAT	temp;
	t_DLIST	*node;
	char	*buf;

	res.nbr_moov = 2147483647;
	buf = NULL;
	node = *stackA;
	while (node)
	{
		temp = calc_moov(node, *stackA, *stackB);
		if (temp.nbr_moov < res.nbr_moov)
		{
			res.nbr_moov = temp.nbr_moov;
			res.count = temp.count;
			res.count_dest = temp.count_dest;
		}
		node = node->next;
	}
	moov_to_do(res.count, res.count_dest, &buf);
	find_best_moov_bis(buf, stackA, stackB);
}
