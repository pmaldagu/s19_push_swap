/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:05:20 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/03/10 11:53:36 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

int		check_ko(t_stack *a)
{
	int		previous;

	previous = 0;
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

int		is_instruction(char *input, t_mem *stack)
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

int		is_endl(char *buf)
{
	int		i;

	i = 0;
	while (buf && buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(void)
{
	char	buf[2];
	char	*tmp;
	char	*line;
	int		ret;

	line = NULL;
	ft_memset(buf, 2);
	while ((ret = read(0, buf, 1)) && buf[0] != '\n')
	{
		tmp = line;
		line = ft_strjoin(line, buf);
		free(tmp);
		ft_memset(buf, 2);
	}
	return (line);
}

int		prompt(t_mem *stack)
{
	char	*line;

	line = NULL;
	while (stack->empty != 0)
	{
		line = get_line();
		if (!is_instruction(line, stack))
		{
			free(line);
			return (0);
		}
		if (stack->debug)
		{
			print_stack(stack->a, 'a');
			print_stack(stack->b, 'b');
		}
		free(line);
	}
	check_ko(stack->a);
	return (1);
}
