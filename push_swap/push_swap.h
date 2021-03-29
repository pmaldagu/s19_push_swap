/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:36:29 by pmaldagu          #+#    #+#             */
/*   Updated: 2021/03/29 14:03:47 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_stack
{
	int				integer;
	struct s_stack	*next;
	struct s_stack	*previous;
	struct s_satck	*end;
}					t_stack;

typedef struct		s_mem
{
	t_stack			*a;
	t_stack			*b;
	int				elems;
	int				*sorted;
	int				chunks;
	int				*pivots;
}					t_mem;

/*
** Debug
*/

void				print_inttab(int *tab, int isze);
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
int					instruction(t_mem *stack, int (*ope)(t_stack **, t_stack **), char option);

/*
** Parser
*/

int					only_digit(char *arg);
int					add_back(t_stack **a, int to_add);
int					parser(int argc, char **argv, t_mem *stack);

/*
** Prepare
*/

int					get_nbr_chink(int size);
int					find_pivots(t_mem *stack);
int					sorting(t_mem *stack);
int					prepare_sort(t_mem *stack);

/*
** Sort
 */

int push_chunks(t_mem *stack);


/*
** Main
*/

t_mem				*get_stack(void);
void				ft_stderror(void);

#endif
