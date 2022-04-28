/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:35:56 by hakaddou          #+#    #+#             */
/*   Updated: 2022/04/27 01:36:08 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdint.h>

typedef struct t_storage
{
	int		max;
	int		max_index;
	int		mid;
	int		min_index;
	int		min;
	int		mid_index;
}			t_storage;

typedef struct t_stack
{
	int				content;
	int				index;
	struct t_stack	*next;
}					t_stack;

void		check(int ac, char **av);

void		ft_free(t_stack *top);

int			ft_atoi(const char *str);

void		ft_check_space(char *str);

void		ft_check_dups(int ac, char **av);

int			ft_strcmp(const char *s1, const char *s2);

void		swap_a(t_stack *top_a);

void		swap_b(t_stack *top_b);

void		swap_ss_a_and_b(t_stack *top_a, t_stack *top_b);

void		push_to_a(t_stack **top_a, t_stack **top_b);

void		push_to_b(t_stack **top_b, t_stack **top_a);

void		reset_index(t_stack *top);

void		rotate_a(t_stack **top_a);

void		add_at_start_list(t_stack **head, int data);

t_stack		*add_end(t_stack *top, int data);

void		rotate_b(t_stack **top_b);

void		rotate_both(t_stack **top_a, t_stack **top_b);

void		reverse_rotate_a(t_stack **top_a);

void		reverse_rotate_b(t_stack **top_b);

void		reverse_rotate_both(t_stack **top_a, t_stack **top_b);

t_stack		*return_tail(t_stack *tail, int i);

void		reset_both_index(t_stack *top_a, t_stack *top_b);

t_stack		*parse_stack(t_stack *top, int ac, char **av);

int			ft_strlens(int ac, char **av, char *sep);

char		*ft_strsjoin(int ac, char **av, char *sep);

int			word_count(char const *s, char c);

char		**ft_split(char const *s, char c);

char		*ft_substr(char const *s, int start, int len);

int			ft_strlen(const char *s);

int			get_max(t_stack *top);

t_storage	*assign(t_storage *storage, t_stack *top_a);

int			get_index(t_stack *top, int max);

int			get_min(t_stack *top);

int			get_size(t_stack *top);

void		*ft_calloc(size_t n, size_t size);

void		ft_bzero(void *s, size_t n);

void		parse_operations(t_stack **top_a, t_stack **top_b);

void		print_stack(t_stack *top, char c);

void		sort_two(t_stack *top_a);

void		sort_three(t_stack **top_a);

void		sort_three_op1(t_stack **top_a);

void		sort_three_op2(t_stack **top_a);

void		sort_four(t_stack **top_a, t_stack **top_b);

void		untill_max_is_last(t_stack **top);

void		untill_max_is_top(t_stack **top);

void		untill_min_is_top(t_stack **top);

void		sort_total(t_stack **top_a, t_stack **top_b);

void		parse_operations(t_stack **top_a, t_stack **top_b);

void		sort_five(t_stack **top_a, t_stack **top_b);

void		push_quart(t_stack **top_a, t_stack **top_b, char c);

int			get_median(t_stack *top);

int			*sort_array (t_stack *top_a);

void 		ft_swap (int *a, int *b);

void		slection_sort(int *a, int size);

int			is_sorted (int *array, t_stack *top_a);

void		phase_one (t_stack **top_a, t_stack **top_b);

int			phase_two(t_stack **top_a, t_stack **top_b);

int			get_dividor(t_stack *top_a);

void		untill_min_is_last(t_stack **top);

void		untill_min_is_top_n(t_stack **top, int n);

int			find_min_n_times (t_stack *top, int n);

int			find_max_n_times (t_stack *top, int n);

void		untill_max_is_top_n(t_stack **top_b, int n);

#endif
