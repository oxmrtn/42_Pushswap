/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moov.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:23:33 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/25 10:26:26 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

// Just an other part of execute_check
void	execute_check_bis(char **moov, int *i, t_DLIST **sA, t_DLIST **sB)
{
	if (!ft_strncmp(moov[*i], "pb", ft_strlen(moov[*i])))
		ft_push(sA, sB);
	else if (!ft_strncmp(moov[*i], "pa", ft_strlen(moov[*i])))
		ft_push(sB, sA);
	else if (!ft_strncmp(moov[*i], "sa", ft_strlen(moov[*i])))
		ft_swap_a_b(sA);
	else if (!ft_strncmp(moov[*i], "sb", ft_strlen(moov[*i])))
		ft_swap_a_b(sB);
	else if (!ft_strncmp(moov[*i], "ss", ft_strlen(moov[*i])))
		ft_ss(sA, sB);
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
	free(moov[*i]);
	(*i)++;
}

// This function check if there is a forbidden moov in the moov list
int	assert_moov(char **moov)
{
	int	i;

	i = 0;
	while (moov[i])
	{
		if (!((!ft_strncmp(moov[i], "sa", ft_strlen(moov[i])))
				|| (!ft_strncmp(moov[i], "sb", ft_strlen(moov[i])))
				|| (!ft_strncmp(moov[i], "ss", ft_strlen(moov[i])))
				|| (!ft_strncmp(moov[i], "pa", ft_strlen(moov[i])))
				|| (!ft_strncmp(moov[i], "pb", ft_strlen(moov[i])))
				|| (!ft_strncmp(moov[i], "ra", ft_strlen(moov[i])))
				|| (!ft_strncmp(moov[i], "rb", ft_strlen(moov[i])))
				|| (!ft_strncmp(moov[i], "rr", ft_strlen(moov[i])))
				|| (!ft_strncmp(moov[i], "rra", ft_strlen(moov[i])))
				|| (!ft_strncmp(moov[i], "rrb", ft_strlen(moov[i])))
				|| (!ft_strncmp(moov[i], "rrr", ft_strlen(moov[i])))))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

void	free_moov(char **moov)
{
	int	i;

	i = 0;
	while (moov[i])
	{
		free(moov[i]);
		i++;
	}
	free(moov);
}

//This function execute the list of moov in str, but split with \n
void	execute_check_moov(char *str, t_DLIST **stackA, t_DLIST **stackB)
{
	char	**moov;
	int		i;

	i = 0;
	moov = ft_split(str, '\n');
	if (!moov)
		return ;
	if (assert_moov(moov))
	{
		ft_free_chain(*stackA);
		ft_free_chain(*stackB);
		free_moov(moov);
		return ;
	}
	while (moov[i])
	{
		execute_check_bis(moov, &i, stackA, stackB);
	}
	free(moov);
	if (is_sorted(*stackA, *stackB))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_chain(*stackA);
	ft_free_chain(*stackB);
}
