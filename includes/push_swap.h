/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:47:28 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/30 15:38:42 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct s_stack
{
	int			*a;
	int			*b;
	int			a_nb;
	int			b_nb;
}		t_stacks;

int		*pars_args(int argc, char **argv, t_stacks *stacks);
int		pars_operation(char *op);
int		mod_stack(char *op, t_stacks *stacks);
void	mod_pa(t_stacks *stacks);
void	mod_pb(t_stacks *stacks);
void	mod_sa(t_stacks *stacks);
void	mod_sb(t_stacks *stacks);
void	mod_ss(t_stacks *stacks);
void	mod_ra(t_stacks *stacks);
void	mod_rb(t_stacks *stacks);
void	mod_rr(t_stacks *stacks);
void	mod_rra(t_stacks *stacks);
void	mod_rrb(t_stacks *stacks);
void	mod_rrr(t_stacks *stacks);
void	print_stacks(t_stacks stacks);
int		is_sorted(t_stacks stacks);
int		sort(t_stacks stacks);
int		mod_write_stack(char *op, t_stacks *stacks);
int		a_go_to(int i, t_stacks *stacks);
int		get_position_b(int next, t_stacks stacks);
int		get_next(t_stacks stacks, int *sorted, int chunk_size);
int		sort_small(t_stacks stacks, int *tab);
int		get_chunk_size(t_stacks stacks);

#endif