/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:18:42 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/26 15:26:20 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mod_write_stack(char *op, t_stacks *stacks)
{
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
	return (mod_stack(op, stacks));
}

int	check_number_chunk(int actual, int *sorted, int max, int chunk_size)
{
	int	i;

	i = max - chunk_size;
	while (i < max)
	{
		if (sorted[i] == actual)
			return (1);
		i++;
	}
	return (0);
}

int	get_next(t_stacks stacks, int *sorted, int chunk_size)
{
	static int	max;
	static int	min;
	int			fwds;
	int			bwds;

	if (min == max)
		max += chunk_size;
	fwds = 0;
	while (!check_number_chunk(stacks.a[fwds], sorted, max, chunk_size))
		fwds++;
	bwds = stacks.a_nb - 1;
	while (!check_number_chunk(stacks.a[bwds], sorted, max, chunk_size))
		bwds--;
	min++;
	if (fwds < stacks.a_nb - bwds)
		return (fwds);
	return (bwds);
}

int	a_go_to(int i, t_stacks *stacks)
{
	int	value;

	value = stacks->a[i];
	if (i < stacks->a_nb / 2)
	{
		while (stacks->a[0] != value)
			mod_write_stack("ra", stacks);
	}
	else
	{
		while (stacks->a[0] != value)
			mod_write_stack("rra", stacks);
	}
	return (0);
}

int	get_position_b(int next, t_stacks stacks)
{
	int	i;

	i = 0;
	while (stacks.b[i] != next)
		i++;
	return (i);
}
