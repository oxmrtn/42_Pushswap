/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_mooves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:48:44 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/27 01:18:51 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

// Just an other part of moov_to_do
void	moov_to_do_bis(int	*count, int *count_dest, char **buffer)
{
	if (*count > 0)
	{
		(*buffer) = ft_strjoin(*buffer, " ra");
		(*count)--;
	}
	else if (*count < 0)
	{
		(*buffer) = ft_strjoin(*buffer, " rra");
		(*count)++;
	}
	if (*count_dest > 0)
	{
		(*buffer) = ft_strjoin(*buffer, " rb");
		(*count_dest)--;
	}
	else if (*count_dest < 0)
	{
		(*buffer) = ft_strjoin(*buffer, " rrb");
		(*count_dest)++;
	}
}

//Merge into a buffer the moov to do
void	moov_to_do(int count, int count_dest, char **moov)
{
	char	*buffer;

	buffer = NULL;
	while (count != 0 || count_dest != 0)
	{
		if (count < 0 && count_dest < 0)
		{
			buffer = ft_strjoin(buffer, " rrr");
			count++;
			count_dest++;
		}
		else if (count > 0 && count_dest > 0)
		{
			buffer = ft_strjoin(buffer, " rr");
			count--;
			count_dest--;
		}
		else
			moov_to_do_bis(&count, &count_dest, &buffer);
	}
	buffer = ft_strjoin(buffer, " pb");
	*moov = buffer;
}

//Just an other part of hr_moov
t_DAT	hr_moov_bis(int count, int count_dest, t_DAT *moov)
{
	if (count < 0)
		return ((*moov).nbr_moov = (-1 * count) + count_dest, *moov);
	else
		return ((*moov).nbr_moov = count + (-1 * count_dest), *moov);
}

//Return a struct containing a buffer with moove
//to do and number of moov to moov a certain element
t_DAT	hr_moov(int count, int count_dest)
{
	t_DAT	moov;

	moov.count = count;
	moov.count_dest = count_dest;
	if (count <= 0 && count_dest <= 0)
	{
		if (count < count_dest)
			return (moov.nbr_moov = (-1 * count) + 1, moov);
		else
			return (moov.nbr_moov = (-1 * count_dest) + 1, moov);
	}
	else if (count >= 0 && count_dest >= 0)
	{
		if (count > count_dest)
			return (moov.nbr_moov = count + 1, moov);
		else
			return (moov.nbr_moov = count_dest + 1, moov);
	}
	else
		return (hr_moov_bis(count, count_dest, &moov));
}

//Meta func that contains every func
t_DAT	calc_moov(t_DLIST *node, t_DLIST *origin, t_DLIST *dest)
{
	int			count;
	int			count_dest;

	count = 0;
	count_dest = 0;
	count = bring_it_to_top(origin, node);
	count_dest = index_to_moov(dest, node);
	return (hr_moov(count, count_dest));
}
