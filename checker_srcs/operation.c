/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:36:55 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/04/01 15:37:44 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

int	push(t_stack **first, t_stack **second)
{
	t_stack	*tmp;

	if (!(*second))
		return (0);
	tmp = (*first);
	(*first) = (*second);
	(*second) = (*second)->next;
	(*first)->next = tmp;
	return (1);
}

int	swap(t_stack **first, t_stack **useless)
{
	t_stack	*swap;

	swap = NULL;
	if (!(*first) || !(*first)->next)
		return (0);
	swap = (*first)->next;
	(*first)->next = (*first)->next->next;
	swap->next = (*first);
	(*first) = swap;
	return (1);
}

int	reverse_rotate(t_stack **first, t_stack **useless)
{
	t_stack	*tmp;
	t_stack	*end;

	tmp = NULL;
	if (!(*first) || !(*first)->next)
		return (0);
	end = (*first);
	while (end->next)
	{
		tmp = end;
		end = end->next;
	}
	tmp->next = NULL;
	end->next = (*first);
	(*first) = end;
	return (1);
}

int	rotate(t_stack **first, t_stack **useless)
{
	t_stack	*tmp;
	t_stack	*second;

	second = NULL;
	tmp = NULL;
	if (!(*first) || !(*first)->next)
		return (0);
	second = (*first)->next;
	tmp = second;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*first);
	tmp->next->next = NULL;
	(*first) = second;
	return (1);
}

int	instruction(t_mem *stack,
		int (*ope)(t_stack **, t_stack **), char option)
{
	if (option == 'a')
		(*ope)(&stack->a, &stack->b);
	else if (option == 'b')
		(*ope)(&stack->b, &stack->a);
	else
	{
		(*ope)(&stack->a, &stack->b);
		(*ope)(&stack->b, &stack->a);
	}
	return (1);
}
