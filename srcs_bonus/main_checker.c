/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:07:04 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/28 19:21:40 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_DLIST	*create_list_checker_extend(char **buffer, t_DLIST *list)
{
	ft_putstr_fd("Error\n", 2);
	if (buffer)
		free_tab(buffer);
	ft_free_chain(list);
	return (NULL);
}

char	*get_instruction(void)
{
	char	*buffer;
	char	*temp;

	buffer = NULL;
	temp = get_next_line(0);
	while (temp)
	{
		buffer = ft_strjoin(buffer, temp);
		free(temp);
		temp = get_next_line(0);
	}
	return (buffer);
}

t_DLIST	*create_list_checker(char *str)
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
			return (create_list_checker_extend(buffer, list));
		ft_add_back_dl(&list, temp);
		i--;
	}
	free_tab(buffer);
	free(str);
	return (list);
}

void	init_checker(char **args)
{
	t_DLIST	*stack_a;
	t_DLIST	*stack_b;
	char	*moov;

	stack_a = create_list_checker(*args);
	if (!stack_a)
	{
		free(*args);
		return ;
	}
	stack_b = NULL;
	moov = get_instruction();
	if (!moov)
	{
		if (is_sorted(stack_a, stack_b))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		ft_free_chain(stack_a);
		ft_free_chain(stack_b);
		return ;
	}
	execute_check_moov(moov, &stack_a, &stack_b);
	free(moov);
}

int	main(int argc, char **argv)
{
	char	*buf;
	int		i;

	i = 1;
	buf = NULL;
	if (argc < 2)
		return (0);
	while (argv[i])
	{
		buf = ft_strjoin(buf, argv[i++]);
		buf = ft_strjoin(buf, " ");
	}
	if (ft_checker(buf))
		return (ft_putstr_fd("Error\n", 2), free(buf), 0);
	init_checker(&buf);
}
