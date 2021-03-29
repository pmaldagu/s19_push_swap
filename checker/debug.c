/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:12:03 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/03/10 11:05:40 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n <= 9 && n >= 0)
		ft_putchar(n + 48);
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
	}
}

void	print_stack(t_stack *to_print, char which)
{
	t_stack *tmp;

	tmp = to_print;
	write(1, "Stack ", 6);
	write(1, &which, 1);
	write(1, ": ", 2);
	while (tmp)
	{
		ft_putnbr(tmp->integer);
		write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}
