/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_stacks_bis_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 09:37:21 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/19 11:14:34 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mod_rrb(t_stacks *stacks)
{
	int	i;
	int	tmp;

	i = stacks->b_nb - 1;
	tmp = stacks->b[i];
	while (i > 0)
	{
		stacks->b[i] = stacks->b[i - 1];
		i--;
	}
	stacks->b[0] = tmp;
}

void	mod_rra(t_stacks *stacks)
{
	int	i;
	int	tmp;

	i = stacks->a_nb - 1;
	tmp = stacks->a[i];
	while (i > 0)
	{
		stacks->a[i] = stacks->a[i - 1];
		i--;
	}
	stacks->a[0] = tmp;
}

void	mod_rrr(t_stacks *stacks)
{
	mod_stack("rra", stacks);
	mod_stack("rrb", stacks);
}

void	mod_rr(t_stacks *stacks)
{
	mod_stack("ra", stacks);
	mod_stack("rb", stacks);
}
