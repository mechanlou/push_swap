/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:23:03 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/30 15:35:57 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_a_sorted(t_stacks stacks)
{
	int	i;

	i = 0;
	while (i < stacks.a_nb - 1)
	{
		if (stacks.a[i] > stacks.a[i + 1])
			return (0);
		i++;
	}	
	return (1);
}

int	is_kinda_sorted(t_stacks stacks, int *tab)
{
	int	i;

	i = 0;
	while (i < stacks.a_nb - 1)
	{
		if (stacks.a[i] > stacks.a[i + 1] && (stacks.a[i] != tab[0]
				|| stacks.a[i + 1] != tab[stacks.a_nb - 1]))
			return (0);
		i++;
	}	
	return (1);
}

int	annoying_case(t_stacks stacks, int *tab)
{
	if (stacks.a_nb == 5 && stacks.a[0] == tab[4] && stacks.a[1] == tab[2]
		&& stacks.a[2] == tab[1] && stacks.a[3] == tab[3]
		&& stacks.a[4] == tab[0])
	{
		mod_write_stack("sa", &stacks);
		mod_write_stack("rra", &stacks);
		mod_write_stack("pb", &stacks);
		mod_write_stack("sa", &stacks);
		mod_write_stack("ra", &stacks);
		mod_write_stack("sa", &stacks);
		mod_write_stack("pa", &stacks);
		free(tab);
		return (1);
	}
	return (0);
}

void	sort_or_push(t_stacks *stacks, int *tab)
{
	if (stacks->a[0] == tab[0] && !is_kinda_sorted(*stacks, tab))
		mod_write_stack("pb", stacks);
	if (stacks->a[0] > stacks->a[1]
		&& (stacks->a[0] != tab[stacks->a_nb + stacks->b_nb - 1]
			|| (stacks->a[1] != tab[1] && stacks->a[1] != tab[0])))
		mod_write_stack("sa", stacks);
	if (stacks->a[0] == tab[0] && !is_kinda_sorted(*stacks, tab))
		mod_write_stack("pb", stacks);
}

int	sort_small(t_stacks stacks, int *tab)
{
	int	i;

	i = 0;
	if (annoying_case(stacks, tab))
		return (1);
	while (!is_a_sorted(stacks))
	{
		sort_or_push(&stacks, tab);
		if (!is_a_sorted(stacks))
		{
			if (stacks.a[stacks.a_nb - 1] > stacks.a[0]
				&& (stacks.a[stacks.a_nb - 1]
					!= tab[stacks.a_nb + stacks.b_nb - 1]
					|| stacks.a[0] != tab[1]))
				mod_write_stack("rra", &stacks);
			else
				mod_write_stack("ra", &stacks);
		}
	}
	if (stacks.b_nb)
		mod_write_stack("pa", &stacks);
	free(tab);
	return (1);
}
