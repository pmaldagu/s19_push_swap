#include "./push_swap.h"

int push_chunks(t_mem *stack)
{
	int i;
	int j;
	int size;

	size = stack->elems;
	i = 0;
	while (size % stack->elems)
		size++;
	size /= stack->chunks;
	while (i < stack->chunks - 1)
	{
		j = 0;
		while (j <= size)
		{
			//printf("pivot = %i\n", stack->pivots[i]);
			if (stack->a->integer <= stack->pivots[i])
			{
				//printf("integer = %i\n", stack->a->integer);
				instruction(stack, push, 'b');
				j++;
			}
			else
				instruction(stack, rotate, 'a');
		}
		i++;
	}
	while (stack->a)
		instruction(stack, push, 'b');
	return (1);
}

int reverse_or_not(t_mem *stack, t_stack *tmp, int pos, char option)
{
	int i;

	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (pos <= (i / 2))
	{
		while (pos)
		{
			instruction(stack, rotate, option);
			pos--;
		}
	}
	else
	{
		while (pos < i)
		{
			instruction(stack, reverse_rotate, option);
			pos++;
		}
	}
	return (1);
}

int push_big_pp(t_mem *stack)
{
	int i;
	t_stack *tmp;
	int	pos;
	int high;

	while (stack->b)
	{
		i = 0;
		tmp = stack->b;
		high = -1;
		pos = 0;
		while (tmp)
		{
			if (high < tmp->integer)
			{
				high = tmp->integer;
				pos = i;
			}
			//printf("high = %i\n", high);
			tmp = tmp->next;
			i++;
		}
		reverse_or_not(stack, stack->b, pos, 'b');/////////
		instruction(stack, push, 'a');
	}
	return (1);
}

int big_sort(t_mem *stack)
{
	//push_chunks(stack);
	sort_opti(stack);
	push_big_pp(stack);
	return (1);
}
