#include "./push_swap.h"

int	reverse_or_not(t_mem *stack, t_stack *tmp, int pos, char option)
{
	int	i;

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

int	push_a(t_mem *stack)
{
	int		i;
	t_stack	*tmp;
	int		pos;
	int		high;

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
			tmp = tmp->next;
			i++;
		}
		reverse_or_not(stack, stack->b, pos, 'b');
		instruction(stack, push, 'a');
	}
	return (1);
}

int	big_sort(t_mem *stack)
{
	sort_opti(stack);
	push_a(stack);
	return (1);
}
