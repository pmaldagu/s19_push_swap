/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:05:20 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/03/10 11:46:46 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

t_mem	*get_stack(void)
{
	static t_mem	stack;

	return (&stack);
}

void	ft_stderror(void)
{
	t_mem			*stack;
	t_stack			*tmp;

	stack = get_stack();
	write(2, "Error\n", 6);
	while (stack->a)
	{
		tmp = stack->a;
		stack->a = stack->a->next;
		free(tmp);
	}
	while (stack->b)
	{
		tmp = stack->b;
		stack->b = stack->b->next;
		free(tmp);
	}
	exit(1);
}

int		main(int argc, char **argv)
{
	t_mem			*stack;

	stack = get_stack();
	stack->empty = -1;
	stack->debug = 0;
	stack->a = NULL;
	stack->b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = 0;
	}
	if (!ft_strcmp(argv[1], "-v"))
	{
		stack->debug = 1;
		argv = &argv[1];
		argc--;
	}
	if (!parser(argc, argv, &stack->a))
		ft_stderror();
	if (!prompt(stack))
		ft_stderror();
	return (0);
}
