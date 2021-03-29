/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:36:29 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/03/10 11:05:00 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_stack
{
	int				integer;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_mem
{
	t_stack			*a;
	t_stack			*b;
	int				empty;
	int				debug;
}					t_mem;

/*
** Debug
*/

void				ft_putchar(char c);
void				ft_putnbr(int n);
void				print_stack(t_stack *to_print, char which);

/*
** Utils
*/

char				*ft_strjoin(char *s1, char *s2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *str);
void				ft_memset(char *arg, int size);
int					ft_strlen(char *str);

/*
** Arg
*/

char				**ft_megafree(char **tab, int y);
int					ft_len_to_sep(char const *str, char c);
int					ft_count_words(char const *str, char c);
char				*ft_tmp_str(const char *str, char c);
char				**ft_split(char const *str, char c);

/*
** Operation
*/

int					push(t_stack **first, t_stack **second);
int					swap(t_stack **first, t_stack **useless);
int					rotate(t_stack **first, t_stack **useless);
int					reverse_rotate(t_stack **first, t_stack **useless);
int					instruction(t_mem *stack,
						int (*ope)(t_stack **, t_stack **), char option);

/*
** Input
*/

int					check_ko(t_stack *a);
int					is_instruction(char *input, t_mem *stack);
int					is_endl(char *buf);
char				*get_line(void);
int					prompt(t_mem *stack);

/*
** Parser
*/

int					only_digit(char *arg);
int					add_back(t_stack **a, int to_add);
int					parser(int argc, char **argv, t_stack **a);

/*
** Quiscksort (TEST)
*/

/*
** Main
*/

t_mem				*get_stack(void);
void				ft_stderror(void);

#endif
