/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:05:20 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/03/29 14:10:32 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_mem *get_stack(void)
{
	static t_mem stack;

	return (&stack);
}

void	ft_stderror(void)
{
	t_mem *stack;
	t_stack *tmp;

	stack = get_stack();
	write(2, "Error\n", 6);
	while(stack->a)
	{
		tmp = stack->a;
		stack->a = stack->a->next;
		free(tmp);
	}
	while(stack->b)
	{
		tmp = stack->b;
		stack->b = stack->b->next;
		free(tmp);
	}
	exit(1);
}

int	main(int argc, char **argv)
{
	t_mem *stack;

	stack = get_stack(); 
	stack->a = NULL;
	stack->b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argv  = ft_split(argv[1], ' ');
		argc = 0;
	}
	if (!parser(argc, argv, stack))
		ft_stderror();
	if (!prepare_sort(stack))
		ft_stderror();
	print_inttab(stack->sorted, stack->elems);
	print_inttab(stack->pivots, stack->chunks - 1);
	push_chunks(stack);
	//print_stack(stack->a, 'a');
	//print_stack(stack->b, 'b');
	return (0);
}
