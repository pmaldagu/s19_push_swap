/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:12:07 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/04/01 14:11:52 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

char	**ft_megafree(char **tab, int y)
{
	while (--y >= 0)
		free(tab[y]);
	free(tab);
	return (NULL);
}

int	ft_len_to_sep(char const *str, char c)
{
	int		i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (i);
}

int	ft_count_words(char const *str, char c)
{
	int	count;
	int	pos;

	count = 1;
	if (str[0] == c)
		count = 0;
	pos = 0;
	while (str[pos] && str[pos + 1])
	{
		if (str[pos] == c && str[pos + 1] != c)
			count++;
		pos++;
	}
	return (count);
}

char	*ft_tmp_str(const char *str, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(sizeof(char) * (ft_len_to_sep(str, c) + 1));
	if (tmp)
	{
		while (str[i] != c && str[i] != '\0')
		{
			tmp[i] = str[i];
			i++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		y;
	char	**split;

	i = 0;
	y = 0;
	split = malloc(sizeof(char *) * (ft_count_words(str, c) + 1));
	while (split && str && str[i] != '\0')
	{
		if (str[i] != c)
		{
			split[y] = ft_tmp_str(&str[i], c);
			if (!split[y])
				return (ft_megafree(split, y));
			i = i + ft_len_to_sep(&str[i], c);
			y++;
		}
		else if (str[i] == c)
			i++;
	}
	if (split)
		split[y] = NULL;
	return (split);
}
