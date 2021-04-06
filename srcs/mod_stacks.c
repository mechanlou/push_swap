/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:00:21 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/19 10:59:08 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	mod_stack_1(char *op, t_stacks *stacks)
{
	int	tmp;
	int	i;

	if (!ft_strcmp(op, "sa"))
	{
		if (stacks->a_nb < 2)
			return (0);
		tmp = stacks->a[0];
		stacks->a[0] = stacks->a[1];
		stacks->a[1] = tmp;
		return (0);
	}
	else if (!ft_strcmp(op, "sb"))
	{
		if (stacks->b_nb < 2)
			return (0);
		tmp = stacks->b[0];
		stacks->b[0] = stacks->b[1];
		stacks->b[1] = tmp;
		return (0);
	}
	else if (!ft_strcmp(op, "ss"))
	{
		mod_stack("sa", stacks);
		mod_stack("sb", stacks);
		return (0);
	}
	else if (!ft_strcmp(op, "pa"))
	{
		if (stacks->b_nb < 1)
			return (0);
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
		return (0);
	}
	else if (!ft_strcmp(op, "pb"))
	{
		if (stacks->a_nb < 1)
			return (0);
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
		return (0);
	}
	else if (!ft_strcmp(op, "ra"))
	{
		tmp = stacks->a[0];
		i = 0;
		while (i < stacks->a_nb - 1)
		{
			stacks->a[i] = stacks->a[i + 1];
			i++;
		}
		stacks->a[i] = tmp;
		return (0);
	}
	else if (!ft_strcmp(op, "rb"))
	{
		tmp = stacks->b[0];
		i = 0;
		while (i < stacks->b_nb - 1)
		{
			stacks->b[i] = stacks->b[i + 1];
			i++;
		}
		stacks->b[i] = tmp;
		return (0);
	}
	else if (!ft_strcmp(op, "rr"))
	{
		mod_stack("ra", stacks);
		mod_stack("rb", stacks);
		return (0);
	}
	else if (!ft_strcmp(op, "rra"))
	{
		i = stacks->a_nb;
		tmp = stacks->a[i];
		while (i > 0)
		{
			stacks->a[i] = stacks->a[i - 1];
			i--;
		}
		stacks->a[0] = tmp;
		return (0);
	}
	else if (!ft_strcmp(op, "rrb"))
	{
		i = stacks->b_nb;
		tmp = stacks->b[i];
		while (i > 0)
		{
			stacks->b[i] = stacks->b[i - 1];
			i--;
		}
		stacks->b[0] = tmp;
		return (0);
	}
	else if (!ft_strcmp(op, "rrr"))
	{
		mod_stack("rra", stacks);
		mod_stack("rrb", stacks);
		return (0);
	}
	else if (!op[0])
		return (1);
	return (-1);
}*/

void	mod_sa(t_stacks *stacks)
{
	int	tmp;

	if (stacks->a_nb >= 2)
	{
		tmp = stacks->a[0];
		stacks->a[0] = stacks->a[1];
		stacks->a[1] = tmp;
	}	
}

void	mod_sb(t_stacks *stacks)
{
	int	tmp;

	if (stacks->b_nb >= 2)
	{	
		tmp = stacks->b[0];
		stacks->b[0] = stacks->b[1];
		stacks->b[1] = tmp;
	}
}

void	mod_ss(t_stacks *stacks)
{
	mod_sa(stacks);
	mod_sb(stacks);
}

int	mod_stack(char *op, t_stacks *stacks)
{
	if (!ft_strcmp(op, "sa"))
		mod_sa(stacks);
	else if (!ft_strcmp(op, "sb"))
		mod_sb(stacks);
	else if (!ft_strcmp(op, "ss"))
		mod_ss(stacks);
	else if (!ft_strcmp(op, "pa"))
		mod_pa(stacks);
	else if (!ft_strcmp(op, "pb"))
		mod_pb(stacks);
	else if (!ft_strcmp(op, "ra"))
		mod_ra(stacks);
	else if (!ft_strcmp(op, "rb"))
		mod_rb(stacks);
	else if (!ft_strcmp(op, "rr"))
		mod_rr(stacks);
	else if (!ft_strcmp(op, "rra"))
		mod_rra(stacks);
	else if (!ft_strcmp(op, "rrb"))
		mod_rrb(stacks);
	else if (!ft_strcmp(op, "rrr"))
		mod_rrr(stacks);
	else
		return (-1);
	return (0);
}
