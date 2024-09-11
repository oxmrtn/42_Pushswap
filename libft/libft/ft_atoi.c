/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:33:47 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/24 16:40:00 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

long	ft_atoi(const char *nptr)
{
	int		i;
	long	signe;
	long	result;

	i = 0;
	result = 0;
	signe = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		i++;
		signe = -1;
	}
	while (ft_isdigit(nptr[i]))
	{
		result *= 10;
		result += (nptr[i] - '0');
		i++;
	}
	return (signe * result);
}
