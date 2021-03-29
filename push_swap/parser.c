/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:08:07 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/03/11 12:40:06 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	only_digit(char *arg)
{
	int i;

	i = 0;
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
	t_stack *tmp;
	t_stack *new;

	tmp = (*a);
	while (tmp && tmp->next)
	{
		if (tmp->integer == to_add)
			return (0);
		tmp = tmp->next;
	}
	if (tmp && tmp->integer == to_add)
		return (0);
	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	new->integer = to_add;
	new->next = NULL;
	new->previous = NULL;
	if (tmp)
	{
		new->previous = tmp;
		tmp->next = new;
	}
	else
		(*a) = new;
	return (1);
}

int	parser(int argc, char **argv, t_mem *stack)
{
	int i;

	i = 1;
	if (argc == 0)
	{
		while (argv[argc])
			argc++;
		i = 0;
	}
	stack->elems = 0;
	while (i < argc)
	{
		if (!only_digit(argv[i]))
			return (0);
		if (!add_back(&stack->a, ft_atoi(argv[i])))
			return (0);
		stack->elems++;
		i++;
	}
	return (1);
}
