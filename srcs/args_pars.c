/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:13:38 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/31 15:22:20 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fret(int *tab, char **tabs)
{
	int	i;

	i = 0;
	if (tabs)
	{
		while (tabs[i])
			free(tabs[i++]);
		free(tabs);
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

int	forbidden_char(char *arg)
{
	int	i;
	int	nb_minus;

	i = 0;
	nb_minus = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-' && arg[i] != ' ')
			return (0);
		if (arg[i] == '-')
			nb_minus++;
		i++;
	}
	if (nb_minus > 1)
		return (0);
	return (1);
}

int	for_the_norm(char **args, int *nb, int i)
{
	if (!forbidden_char(args[i]))
		return (-1);
	if (ft_strlen(args[i]) == 1 && args[i][0] == '-')
		return (-1);
	*nb = ft_atoi(args[i]);
	if ((*nb < 0 && args[i][0] != '-')
		|| (*nb > 0 && args[i][0] == '-'))
		return (-1);
	return (0);
}

int	*pars_arg(char *arg, t_stacks *stacks)
{
	char	**args;
	int		*tab;
	int		i;

	stacks->a_nb = 0;
	args = ft_split(arg, ' ');
	if (!args)
		return (NULL);
	while (args[stacks->a_nb])
		stacks->a_nb = stacks->a_nb + 1;
	tab = malloc(sizeof(int) * stacks->a_nb);
	if (!tab)
		return (fret(NULL, args));
	i = 0;
	while (args[i])
	{
		if (for_the_norm(args, &tab[i], i) == -1)
			return (fret(tab, args));
		i++;
	}
	fret(NULL, args);
	return (tab);
}

int	*pars_args(int argc, char **argv, t_stacks *stacks)
{
	int	*tab;
	int	i;

	if (ft_strchr(argv[1], ' ') && argc > 2)
		return (NULL);
	if (ft_strchr(argv[1], ' '))
		return (pars_arg(argv[1], stacks));
	stacks->a_nb = argc - 1;
	tab = malloc(sizeof(int) * argc - 1);
	if (!tab)
		return (tab);
	i = 1;
	while (i < argc)
	{
		if (!forbidden_char(argv[i])
			|| (ft_strlen(argv[i]) == 1 && argv[i][0] == '-'))
			return (fret(tab, NULL));
		tab[i - 1] = ft_atoi(argv[i]);
		if ((tab[i - 1] < 0 && argv[i][0] != '-')
			|| (tab[i - 1] > 0 && argv[i][0] == '-'))
			return (fret(tab, NULL));
		i++;
	}
	return (tab);
}
