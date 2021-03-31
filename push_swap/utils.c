/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:52:45 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/03/31 18:34:37 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	i = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(i + 1);
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		join[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		join[j++] = s2[i];
		i++;
	}
	join[j] = 0;
	return (join);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	value;

	i = 0;
	sign = 1;
	value = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = ((value * 10) + (str[i] - 48));
		i++;
	}
	if (value > 2147483648 && value > 9223372036854775807)
		ft_stderror();
	return (value * sign);
}

void	ft_memset(char *arg, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arg[i] = 0;
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
