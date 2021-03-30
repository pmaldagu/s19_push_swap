/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:56:08 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/03/30 15:29:44 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int is_in_order(t_mem *stack, t_stack *tmp)
{
	int		i;

	i = 0;
	while (tmp)
	{
		if (tmp->integer != stack->sorted[i])
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int size_3(t_mem *stack, t_stack *tmp)
{
	int i;

	i = 0;
	while (i < 1)
	{
		tmp = stack->a;
		if (tmp->integer > tmp->next->integer &&
				tmp->integer > tmp->next->next->integer)
			instruction(stack, rotate, 'a');
		else if (tmp->integer < tmp->next->integer &&
				tmp->next->integer > tmp->next->next->integer)
			instruction(stack, reverse_rotate, 'a');
		if (!is_in_order(stack, stack->a))
			instruction(stack, swap, 'a');
		i++;
	}
	return (1);
}

int	size_4(t_mem *stack, t_stack *tmp)
{
	int	pos;
	int min;
	int i;

	i = 0;
	pos = 0;
	min = tmp->integer;
	while (tmp)
	{
		if (tmp->integer < min)
		{
			min = tmp->integer;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	reverse_or_not(stack, stack->a, pos, 'a');
	if (is_in_order(stack, stack->a))
		return (1);
	instruction(stack, push, 'b');
	size_3(stack, stack->a);
	instruction(stack, push, 'a');
	return (1);
}

int	size_5(t_mem *stack, t_stack *tmp)
{
	int	pos;
	int min;
	int i;

	i = 0;
	pos = 0;
	min = tmp->integer;
	while (tmp)
	{
		if (tmp->integer < min)
		{
			min = tmp->integer;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	reverse_or_not(stack, stack->a, pos, 'a');
	if (is_in_order(stack, stack->a))
		return (1);
	instruction(stack, push, 'b');
	size_4(stack, stack->a);
	instruction(stack, push, 'a');
	return (1);
}

int	how_to_sort(t_mem *stack)
{
	if (stack->elems == 1 || is_in_order(stack, stack->a))
		return (1);
	else if (stack->elems == 2)
	{	
		if (stack->a->integer > stack->a->next->integer)
			instruction(stack, swap, 'a');
		return (1);
	}
	else if (stack->elems == 3)
		return (size_3(stack, stack->a));
	else if (stack->elems == 4)
		return (size_4(stack, stack->a));
	else if (stack->elems == 5)
		return (size_5(stack, stack->a));
	else
		return (big_sort(stack));
}
