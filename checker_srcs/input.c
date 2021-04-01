/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:05:20 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/04/01 17:01:50 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

int	check_ko(t_stack *a, t_stack *b)
{
	int	previous;

	previous = 0;
	if (b)
	{
		write(1, "KO\n", 3);
		return (1);
	}
	while (a)
	{
		previous = a->integer;
		a = a->next;
		if (a && previous > a->integer)
		{
			write(1, "KO\n", 3);
			return (1);
		}
	}
	write(1, "OK\n", 3);
	return (0);
}

int	is_instruction(char *input, t_mem *stack)
{
	if (!ft_strcmp(input, "sa"))
		return (instruction(stack, &swap, 'a'));
	else if (!ft_strcmp(input, "sb"))
		return (instruction(stack, &swap, 'b'));
	else if (!ft_strcmp(input, "ss"))
		return (instruction(stack, &swap, 's'));
	else if (!ft_strcmp(input, "pa"))
		return (instruction(stack, &push, 'a'));
	else if (!ft_strcmp(input, "pb"))
		return (instruction(stack, &push, 'b'));
	else if (!ft_strcmp(input, "ra"))
		return (instruction(stack, &rotate, 'a'));
	else if (!ft_strcmp(input, "rb"))
		return (instruction(stack, &rotate, 'b'));
	else if (!ft_strcmp(input, "rr"))
		return (instruction(stack, &rotate, 'r'));
	else if (!ft_strcmp(input, "rra"))
		return (instruction(stack, &reverse_rotate, 'a'));
	else if (!ft_strcmp(input, "rrb"))
		return (instruction(stack, &reverse_rotate, 'a'));
	else if (!ft_strcmp(input, "rrr"))
		return (instruction(stack, &reverse_rotate, 'a'));
	else
		return (0);
}

int	get_line(char **line)
{
	char	buf[2];
	char	*tmp;
	int		ret;

	(*line) = NULL;
	ft_memset(buf, 2);
	while (buf[0] != '\n')
	{
		ft_memset(buf, 2);
		ret = read(0, buf, 1);
		if (!ret)
		{
			free((*line));
			return (1);
		}
		if (buf[0] != '\n')
		{
			tmp = (*line);
			(*line) = ft_strjoin((*line), buf);
			free(tmp);
		}
	}
	return (0);
}

int	prompt(t_mem *stack)
{
	char	*line;
	int		stop;

	line = NULL;
	stop = 0;
	while (1)
	{
		stop = get_line(&line);
		if (stop)
			break ;
		if (!is_instruction(line, stack))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	check_ko(stack->a, stack->b);
	return (1);
}
