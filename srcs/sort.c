/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:16:51 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/30 15:38:51 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	cpy_stack_tab(t_stacks stacks, int *tab)
{
	int	i;

	i = 0;
	while (i < stacks.a_nb)
	{
		tab[i] = stacks.a[i];
		i++;
	}
}

int	*pre_sort(t_stacks stacks)
{
	int	i;
	int	*sorted_tab;
	int	tmp;

	sorted_tab = malloc(sizeof(int) * stacks.a_nb);
	if (!sorted_tab)
		return (NULL);
	cpy_stack_tab(stacks, sorted_tab);
	i = 0;
	while (!is_sorted_tab(sorted_tab, stacks.a_nb))
	{
		if (i == stacks.a_nb - 1)
			i = 0;
		else
		{
			if (sorted_tab[i] > sorted_tab[i + 1])
			{
				tmp = sorted_tab[i];
				sorted_tab[i] = sorted_tab[i + 1];
				sorted_tab[i + 1] = tmp;
			}
			i++;
		}
	}
	return (sorted_tab);
}

void	push_sort_to_a(t_stacks *stacks, int *tab)
{
	int	i;

	i = stacks->b_nb - 1;
	while (i + 1)
	{
		if (get_position_b(tab[i], *stacks) >= stacks->b_nb / 2)
		{
			while (stacks->b[0] != tab[i])
				mod_write_stack("rrb", stacks);
			mod_write_stack("pa", stacks);
		}
		else
		{
			while (stacks->b[1] != tab[i] && stacks->b[0] != tab[i])
				mod_write_stack("rb", stacks);
			if (stacks->b[1] == tab[i])
				mod_write_stack("sb", stacks);
			mod_write_stack("pa", stacks);
		}
		i--;
	}
}

int	sort(t_stacks stacks)
{
	int	i;
	int	*tab;
	int	chunk_size;

	i = 0;
	tab = pre_sort((stacks));
	if (!tab)
		return (0);
	if (stacks.a_nb < 10)
		return (sort_small(stacks, tab));
	else
		chunk_size = get_chunk_size(stacks);
	while (stacks.a_nb)
	{
		i = get_next(stacks, tab, chunk_size);
		if (a_go_to(i, &stacks))
			return (0);
		mod_write_stack("pb", &stacks);
	}
	push_sort_to_a(&stacks, tab);
	free(tab);
	return (1);
}
