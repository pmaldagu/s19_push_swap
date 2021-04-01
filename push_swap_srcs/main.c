/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:05:20 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/04/01 14:08:46 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	init_struct(t_mem *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->elems = 0;
	stack->sorted = NULL;
	stack->chunks = 0;
	stack->size = 0;
	stack->pivots = NULL;
}

t_mem	*get_struct(void)
{
	static t_mem	stack;

	return (&stack);
}

void	free_everything(t_mem *stack)
{
	t_stack	*tmp;

	free(stack->sorted);
	free(stack->pivots);
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
}

void	ft_stderror(void)
{
	t_mem	*stack;

	stack = get_struct();
	write(2, "Error\n", 6);
	free_everything(stack);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_mem	*stack;
	int		i;

	stack = get_struct();
	init_struct(stack);
	i = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = 0;
	}
	if (!parser(argc, argv, stack) || !prepare_sort(stack))
		ft_stderror();
	how_to_sort(stack);
	free_everything(stack);
	return (0);
}
