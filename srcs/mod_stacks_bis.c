/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_stacks_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:48:58 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/19 11:14:26 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mod_rb(t_stacks *stacks)
{
	int	i;
	int	tmp;

	tmp = stacks->b[0];
	i = 0;
	while (i < stacks->b_nb - 1)
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->b[i] = tmp;
}

void	mod_ra(t_stacks *stacks)
{
	int	i;
	int	tmp;

	tmp = stacks->a[0];
	i = 0;
	while (i < stacks->a_nb - 1)
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->a[i] = tmp;
}

void	mod_pb(t_stacks *stacks)
{
	int	i;

	if (stacks->a_nb >= 1)
	{
		i = stacks->b_nb++;
		while (i > 0)
		{
			stacks->b[i] = stacks->b[i - 1];
			i--;
		}
		stacks->b[0] = stacks->a[0];
		while (i < stacks->a_nb - 1)
		{
			stacks->a[i] = stacks->a[i + 1];
			i++;
		}
		stacks->a_nb--;
	}
}

void	mod_pa(t_stacks *stacks)
{
	int	i;

	if (stacks->b_nb >= 1)
	{
		i = stacks->a_nb++;
		while (i > 0)
		{
			stacks->a[i] = stacks->a[i - 1];
			i--;
		}
		stacks->a[0] = stacks->b[0];
		while (i < stacks->b_nb - 1)
		{
			stacks->b[i] = stacks->b[i + 1];
			i++;
		}
		stacks->b_nb--;
	}
}
