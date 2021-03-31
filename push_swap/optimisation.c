/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimistaion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:06:03 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/03/31 18:52:10 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

//4 2 1 3
//
//4 3 2 1

// 0 1 2 | 3 4 5 | 6 7 8 | 9 10

int	who_is_the_nearest(t_mem *stack, int pos_pivot)
{
	t_stack	*tmp;
	int		hold_first;
	int		hold_second;
	int		i;
	int		prev;

	tmp = stack->a;
	hold_first = -1;
	hold_second = -1;
	i = 0;
	prev = -1;
	//printf("pivot = %i\n", stack->pivots[pos_pivot]);
	if (pos_pivot > 0)
		prev = stack->pivots[pos_pivot - 1];
	while (tmp && pos_pivot < stack->chunks - 1)
	{
		if (tmp->integer <= stack->pivots[pos_pivot] && tmp->integer > prev)
		{
			hold_first = i;
			tmp = tmp->next;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	i++;
	while (tmp && pos_pivot < stack->chunks - 1)
	{
		if (tmp->integer <= stack->pivots[pos_pivot] && tmp->integer > prev)
			hold_second = i;
		tmp = tmp->next;
		i++;
	}
	//printf("hold_first = %i\n", hold_first);
	//printf("hold_second = %i\n", hold_second);
	if (hold_first < hold_second || hold_second < 0)
		return (hold_first);
	else
		return (hold_second);
}

int	nearest_by_pair(t_mem *stack, int pos_pivot, int *rb)
{
	int	pos;
	int pos_next;
	int nb_ope;
	int nb_ope_next;

	pos_next = -1;
	pos = who_is_the_nearest(stack, pos_pivot);
	//printf("nearest = %i\n", pos);
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
	if ((pos_next >= 0 && nb_ope > nb_ope_next) || pos < 0)
	{
		//printf("pos_next = %i\n", pos_next);
		return (pos_next);
	}
	else
	{
		(*rb) = 1;
		//printf("pos = %i\n", pos);
		return (pos);
	}
}

int	double_rotation(t_mem *stack, int pos_pivot, int rb)
{
	int	prev_pivot;
	int	r;

	r = nearest_by_pair(stack, pos_pivot, &rb);
	if (pos_pivot >= stack->chunks - 2)
		return (1);
	if (r > 0 && r <= (stack->elems / 2) && stack->b 
			&& stack->b->integer <= stack->pivots[pos_pivot] && stack->b->next 
			&& stack->b->next->integer > stack->pivots[0])
		instruction(stack, rotate, 'r');
	if (stack->b && stack->b->integer <= stack->pivots[pos_pivot] && stack->b->next 
			&& stack->b->next->integer > stack->pivots[0])
		instruction(stack, rotate, 'b');
	return (1);
}

int	push_b(t_mem *stack)
{
	int	to_push;
	int	pos_pivot;
	int	pos;
	int	rb;

	pos_pivot = -2;
	to_push = 0;
	rb = 0;
	while (stack->a)
	{
		if (rb)
			rb--;
		if (!to_push)
		{
			pos_pivot += 2;
			to_push += (stack->size * 2);
		}
		pos = nearest_by_pair(stack, pos_pivot, &rb);
		if (pos > 0)
			reverse_or_not(stack, stack->a, pos, 'a');
		to_push--;
		instruction(stack, push, 'b');
		//printf("pivot = %i\n", stack->pivots[pos_pivot]);
		double_rotation(stack, pos_pivot, rb);
	}
	return (1);
}

int sort_opti(t_mem *stack)
{
	stack->size = stack->elems;
	while (stack->size % stack->chunks)
		stack->size++;
	stack->size /= stack->chunks;
	push_b(stack);
	return (1);
}


