/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:12:28 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/22 14:44:59 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stacks stacks)
{
	int	i;

	i = 0;
	if (stacks.b_nb)
		return (0);
	while (i < stacks.a_nb - 1)
	{
		if (stacks.a[i + 1] < stacks.a[i])
			return (0);
		i++;
	}
	return (1);
}

void	print_stacks(t_stacks stacks)
{
	int	i;
	int	size;

	i = 0;
	size = stacks.a_nb + stacks.b_nb;
	while (i < size)
	{
		write(1, "|", 1);
		if (i >= stacks.a_nb)
			write(1, "   ", 3);
		else
			ft_printf("%-3d", stacks.a[i]);
		write(1, "|", 1);
		if (i >= stacks.b_nb)
			write(1, "   ", 3);
		else
			ft_printf("%-3d", stacks.b[i]);
		write(1, "|\n", 2);
		i++;
	}
	write(1, "| - | - |\n| a | b |\n", 20);
}
