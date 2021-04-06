/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:36:42 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/30 15:39:02 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(t_stacks stacks)
{
	if (stacks.a_nb < 20)
		return (3);
	else if (stacks.a_nb < 200)
		return (15);
	else
		return (40);
}
