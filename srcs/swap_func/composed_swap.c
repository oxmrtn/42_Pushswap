/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composed_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:47:42 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/23 14:10:16 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_ss(t_DLIST **stackA, t_DLIST **stackB)
{
	ft_swap_a_b(stackA);
	ft_swap_a_b(stackB);
}

void	ft_rr(t_DLIST **stackA, t_DLIST **stackB)
{
	ft_rotate(stackA);
	ft_rotate(stackB);
}

void	ft_rrr(t_DLIST **stackA, t_DLIST **stackB)
{
	ft_reverse_rotate(stackA);
	ft_reverse_rotate(stackB);
}
