/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimistaion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:06:03 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/03/30 18:36:12 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

//4 2 1 3

// 0 1 2 | 3 4 5 | 6 7 8 | 9 10

int	who_is_the_nearest(t_mem *stack, int pos_pivot)
{
	t_stack *tmp;
	int hold_first;
	int hold_second;
	int	i;

	tmp = stack->a;
	hold_first = 0;
	hold_second = 0;
	i = 0;
	printf("pos_pivot = %i\n", pos_pivot);
	while (tmp && !hold_first && i < (stack->elems / 2))
	{
		if (tmp->integer <= stack->pivots[pos_pivot])
			hold_first = i;
		tmp = tmp->next;
		i++;
	}
	while (tmp)
	{
		if (tmp->integer <= stack->pivots[pos_pivot])
			hold_second = i;
		tmp = tmp->next;
		i++;
	}
	if (hold_first < hold_second)
		return (hold_first);
	else
		return (hold_second);
}

int nearest_by_pair(t_mem *stack, int pos_pivot, int *rb)
{
	int pos;
	int pos_next;
	int nb_ope;
	int nb_ope_next;

	pos_next = -1;
	pos = who_is_the_nearest(stack, pos_pivot);
	if (pos >= (stack->elems / 2))
		nb_ope = stack->elems - pos;
	else
		nb_ope = pos;
	if ((pos_pivot + 1) < stack->chunks - 1)
		pos_next = who_is_the_nearest(stack, pos_pivot + 1);
	if (pos_next >= 0)
	{
		if (pos > (stack->elems / 2))
			nb_ope_next = stack->elems - pos_next;
		else
			nb_ope_next = pos_next;
	}
	if (nb_ope > nb_ope_next)
	{
		printf("pos_next = %i\n", pos_next);
		return (pos_next);
	}
	else
	{
		(*rb) = 1;
		printf("pos = %i\n", pos);
		return (pos);
	}
}

int	push_b(t_mem *stack)
{
	int to_push;
	int pos_pivot;
	int pos;
	int	rb;

	pos_pivot = -1;
	to_push = 0;
	rb = 0;
	while (stack->a)
	{
		if (rb)
			rb--;
		if (!to_push)
		{
			pos_pivot++;
			to_push = stack->size;
			if (pos_pivot + 1 < stack->chunks - 1)
				to_push += stack->size;
		}
		pos = nearest_by_pair(stack, pos_pivot, &rb);
		reverse_or_not(stack, stack->a, pos, 'a');
		instruction(stack, push, 'b');
		to_push--;
		if (who_is_the_nearest(stack, pos_pivot) < (stack->elems / 2) && rb 
				&& stack->b && stack->b->integer <= stack->pivots[pos_pivot])
			instruction(stack, rotate, 'r');
		else if (rb && stack->b && stack->b->integer <= stack->pivots[pos_pivot] )
			instruction(stack, rotate, 'b');
	}
	return (1);
}

int sort_opti(t_mem *stack)
{
	stack->size = 0;
	while (stack->size % stack->elems)
		stack->size++;
	stack->size /= stack->chunks;
	push_b(stack);
	return (1);
}


