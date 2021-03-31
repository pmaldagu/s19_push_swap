/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:44:38 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/03/31 16:14:58 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int     get_nbr_chunck(int size)
{
	if (size < 10)
		return (2);
    if (size < 99)
        return (4);
    else if (size < 495)
        return (8);
    else
        return (18);
}

int	find_pivots(t_mem *stack)
{
	int i;
	int	stop;
	int pos;

	i = 0;
	stack->chunks = get_nbr_chunck(stack->elems);
	stack->pivots = malloc(sizeof(int) * stack->chunks - 1);
	if (!stack->pivots)
		return (0);
	stop = stack->elems;
	while (stop % stack->chunks)
		stop++;
	stop = stop / stack->chunks;
	pos = stop;
	while (i < stack->chunks - 1)
	{
		stack->pivots[i] = stack->sorted[stop - 1];
		stop += pos;
		i++;
	}
	return (1);
}

int sorting(t_mem *stack)
{
	int i;
	int j;
	int swap;

	i = 0;
	while (i < stack->elems - 1)
	{
		j = i + 1;
		while (j < stack->elems)
		{
			if (stack->sorted[i] > stack->sorted[j])
			{
				swap = stack->sorted[i];
				stack->sorted[i] = stack->sorted[j];
				stack->sorted[j] = swap;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	prepare_sort(t_mem *stack)
{
	t_stack *tmp;
	int		i;

	tmp = stack->a;
	i = -1;
	stack->sorted = malloc(stack->elems * sizeof(int));
	if (!stack->sorted)
		return (0);
	while (tmp)
	{
		i++;
		stack->sorted[i] = tmp->integer;
		tmp = tmp->next;
	}
	sorting(stack);
	return (find_pivots(stack));
}
