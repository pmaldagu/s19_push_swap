#include "./push_swap.h"

//int hold_second(t_stack *a, int pivot)
//{
//	int i;
//	int pos;
//
//	i = 0;
//	while (a)
//	{
//		if (a->integer <= pivot)
//			pivot = i;
//		a = a->next;
//		i++;
//	}
//	return (pos);
//}
//
//int	hold_first(t_stack *a, int pivot)
//{
//	int pos;
//
//	pos = 0;
//	while (a && a->integer > pivot)
//	{
//		a = a->next;
//		pos++;
//	}
//	return (pos);
//}

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

int reverse_or_not(t_mem *stack, int pos)
{
	t_stack *tmp;
	int i;

	i = 0;
	tmp = stack->b;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (pos < (i / 2))
	{
		while (pos)
		{
			instruction(stack, rotate, 'b');
			pos--;
		}
	}
	else
	{
		while (pos < i)
		{
			instruction(stack, reverse_rotate, 'b');
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
		reverse_or_not(stack, pos);
		instruction(stack, push, 'a');
	}
	return (1);
}
