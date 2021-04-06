/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:01:10 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/31 14:17:16 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_perror(t_stacks stacks, char *str)
{
	free(stacks.a);
	free(stacks.b);
	free(str);
	write (2, "Error\n", 6);
	return (-1);
}

int	prep_stacks(t_stacks *stacks, int argc, char **argv)
{
	int	i;
	int	j;

	stacks->a = pars_args(argc, argv, stacks);
	stacks->b = malloc(sizeof(int) * stacks->a_nb);
	if (!stacks->a || !stacks->b)
		return (-1);
	stacks->b_nb = 0;
	i = 0;
	while (i < stacks->a_nb)
	{
		j = i + 1;
		while (j < stacks->a_nb)
		{
			if (stacks->a[i] == stacks->a[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	input_operators(t_stacks *stacks)
{
	char		*buffer;
	int			ret;
	int			error;

	error = 0;
	ret = 1;
	while (ret > 0 && !error)
	{
		ret = get_next_line(0, &buffer);
		if (ret == -1)
			return (free_perror(*stacks, buffer));
		if (ret > 0)
		{
			error = mod_stack(buffer, stacks);
			if (error == -1)
				return (free_perror(*stacks, buffer));
			free(buffer);
		}
	}
	free(buffer);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			error;

	if (argc == 1 || !argv[1][0])
		return (0);
	error = prep_stacks(&stacks, argc, argv);
	if (error)
		return (free_perror(stacks, NULL));
	error = input_operators(&stacks);
	if (error)
		return (error);
	if (is_sorted(stacks))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(stacks.a);
	free(stacks.b);
	return (0);
}
