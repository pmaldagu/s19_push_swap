#include "./push_swap.h"

int hold_second(t_stack *a, int pivot)
{
	int i;
	int pos;

	i = 0;
	while (a)
	{
		if (a->integer <= pivot)
			pivot = i;
		a = a->next;
		i++;
	}
	return (pos);
}

int	hold_first(t_stack *a, int pivot)
{
	int pos;

	pos = 0;
	while (a && a->integer > pivot)
	{
		a = a->next;
		pos++;
	}
	return (pos);
}

int push_chunks(t_mem *stack)
{
	int i;
	int j;
	int size;
	int rot;

	size = stack->elems;
	i = 0;
	while (size % stack->elems)
		size++;
	size /= stack->chunks;
	while (i < stack->chunks - 1)
	{
		j = 0;
		while (j < size)
		{
			if (stack->a->integer <= stack->pivots[i])
			{
				instruction(stack, push, 'b');
				j++;
			}
			else
				instruction(stack, rotate, 'a');
		}
		i++;
	}
	return (1);
}
