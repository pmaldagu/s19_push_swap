/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:08:07 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/04/01 16:54:11 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

int	free_argv(char ***argv, int malloc)
{
	int		i;
	char	**tmp;

	tmp = (*argv);
	i = 0;
	if (!malloc)
		return (0);
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free((*argv));
	return (0);
}

int	only_digit(char *arg)
{
	int	i;

	i = 0;
	if (arg && arg[i] && arg[i] == '-')
		i++;
	while (arg && arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	add_back(t_stack **a, int to_add)
{
	t_stack	*tmp;
	t_stack	*new;

	tmp = (*a);
	while (tmp && tmp->next)
	{
		if (tmp->integer == to_add)
			return (0);
		tmp = tmp->next;
	}
	if (tmp && tmp->integer == to_add)
		return (0);
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->integer = to_add;
	new->next = NULL;
	if (tmp)
		tmp->next = new;
	else
		(*a) = new;
	return (1);
}

int	parser(int argc, char **argv, t_mem *stack)
{
	int	i;
	int	malloc;

	i = 1;
	malloc = 0;
	if (argc == 0)
	{
		malloc = 1;
		while (argv[argc])
			argc++;
		i = 0;
	}
	while (i < argc)
	{
		if (!only_digit(argv[i]))
			return (free_argv(&argv, malloc));
		if (!add_back(&stack->a, ft_atoi(argv[i])))
			return (free_argv(&argv, malloc));
		i++;
	}
	free_argv(&argv, malloc);
	return (1);
}
