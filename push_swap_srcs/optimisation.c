/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimistaion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:06:03 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/04/01 14:08:25 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

//4 2 1 3
//
//4 3 2 1

// 0 1 2 | 3 4 5 | 6 7 8 | 9
//
// -4 -3 -2 | -1 0 1 | 2 3 4 | 5

int	in_the_beginning(t_mem *stack, t_stack **tmp, int pos_pivot,
		int *hold_first)
{
	int	i;
	int	prev;

	i = 0;
	prev = stack->sorted[0] - 1;
	if (pos_pivot > 0)
		prev = stack->pivots[pos_pivot - 1];
	while ((*tmp) && pos_pivot < stack->chunks - 1)
	{
		if ((*tmp)->integer <= stack->pivots[pos_pivot]
			&& (*tmp)->integer > prev)
		{
			(*hold_first) = i;
			(*tmp) = (*tmp)->next;
			break ;
		}
		(*tmp) = (*tmp)->next;
		i++;
	}
	return (i + 1);
}

int	who_is_the_nearest(t_mem *stack, t_stack *tmp, int pos_pivot)
{
	int		hold[2];
	int		i;
	int		prev;

	hold[0] = -1;
	hold[1] = -1;
	i = 0;
	prev = stack->sorted[0] - 1;
	if (pos_pivot > 0)
		prev = stack->pivots[pos_pivot - 1];
	i = in_the_beginning(stack, &tmp, pos_pivot, &hold[0]);
	while (tmp && pos_pivot < stack->chunks - 1)
	{
		if (tmp->integer <= stack->pivots[pos_pivot] && tmp->integer > prev)
			hold[1] = i;
		tmp = tmp->next;
		i++;
	}
	if (hold[0] < hold[1] || hold[1] < 0)
		return (hold[0]);
	else
		return (hold[1]);
}

int	nearest_by_pair(t_mem *stack, int pos_pivot)
{
	int	pos;
	int	pos_next;
	int	nb_ope;
	int	nb_ope_next;

	pos_next = -1;
	pos = who_is_the_nearest(stack, stack->a, pos_pivot);
	if (pos >= (stack->elems / 2))
		nb_ope = stack->elems - pos;
	else
		nb_ope = pos;
	if ((pos_pivot + 1) < stack->chunks - 1)
		pos_next = who_is_the_nearest(stack, stack->a, pos_pivot + 1);
	if (pos_next >= 0)
	{
		if (pos > (stack->elems / 2))
			nb_ope_next = stack->elems - pos_next;
		else
			nb_ope_next = pos_next;
	}
	if ((pos_next >= 0 && nb_ope > nb_ope_next) || pos < 0)
		return (pos_next);
	else
		return (pos);
}

int	double_rotation(t_mem *stack, int pos_pivot)
{
	int	prev_pivot;
	int	r;

	r = nearest_by_pair(stack, pos_pivot);
	if (pos_pivot >= stack->chunks - 2)
		return (1);
	if (r > 0 && r <= (stack->elems / 2) && stack->b
		&& stack->b->integer <= stack->pivots[pos_pivot] && stack->b->next
		&& stack->b->next->integer > stack->pivots[0])
		instruction(stack, rotate, 'r');
	if (stack->b && stack->b->integer <= stack->pivots[pos_pivot]
		&& stack->b->next
		&& stack->b->next->integer > stack->pivots[0])
		instruction(stack, rotate, 'b');
	return (1);
}

int	push_b(t_mem *stack)
{
	int	to_push;
	int	pos_pivot;
	int	pos;

	pos_pivot = -2;
	to_push = 0;
	stack->size = stack->elems;
	while (stack->size % stack->chunks)
		stack->size++;
	stack->size /= stack->chunks;
	while (stack->a)
	{
		if (!to_push)
		{
			pos_pivot += 2;
			to_push += (stack->size * 2);
		}
		pos = nearest_by_pair(stack, pos_pivot);
		if (pos > 0)
			reverse_or_not(stack, stack->a, pos, 'a');
		to_push--;
		instruction(stack, push, 'b');
		double_rotation(stack, pos_pivot);
	}
	return (1);
}
