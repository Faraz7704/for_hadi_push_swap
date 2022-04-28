/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operations_v2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 07:01:53 by hakaddou          #+#    #+#             */
/*   Updated: 2022/04/26 21:24:13 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *top_a)
{
	t_stack	*tmp;

	tmp = NULL;
	tmp = top_a;
	if (tmp->next->content < tmp->content)
		swap_a(tmp);
}

void	sort_three_op1(t_stack **top_a)
{
	rotate_a(top_a);
	swap_a(*top_a);
}

void	sort_three_op2(t_stack **top_a)
{
	reverse_rotate_a(top_a);
	swap_a(*top_a);
}

void	sort_three(t_stack **top_a)
{
	int	min_index;
	int	max_index;

	max_index = get_index(*top_a, get_max(*top_a));
	min_index = get_index(*top_a, get_min(*top_a));
	if (max_index == 0 && min_index == 2)
		sort_three_op1(top_a);
	else if (max_index == 2 && min_index == 1)
		swap_a(*top_a);
	else if (max_index == 1 && min_index == 0)
		sort_three_op2(top_a);
	else if (max_index == 1 && min_index == 2)
		reverse_rotate_a(top_a);
	else if (max_index == 0 && min_index == 1)
		rotate_a(top_a);
}

void	sort_four(t_stack **top_a, t_stack **top_b)
{
	untill_min_is_top(top_a);
	push_to_b(top_b, top_a);
	sort_three(top_a);
	push_to_a(top_a, top_b);
}

void	push_quart(t_stack **top_a, t_stack **top_b, char c)
{
	int		quart;
	int		i;
	t_stack	*tmp;
	
	if ((!(*top_a) && c == 'a') || (!(*top_b) && c == 'b'))
	{
		write (2, "error from quart function\n", 26);
		exit (1);
	}
	i = 0;
	quart = get_size(*top_a) / 4;
	tmp = *top_a;
	while (i < quart)
	{
		if (c == 'a')
		push_to_b(top_b, top_a);
		if (c == 'b')
		push_to_a(top_a, top_b);
		i++;
	}
}

int	get_median(t_stack *top)
{
	int	median;
	t_stack *tmp;
	
	if (!top)
		return (0);
	tmp = NULL;
	median = 0;
	tmp = top;
	while (tmp != NULL)
	{
		median += tmp->content;
		tmp = tmp->next;
	}
	return (median / 2);
}

int	*parse_array (t_stack *top_a, int *array)
{
	int	i;
	t_stack *tmp;
	int	size;

	size = get_size(top_a);
	tmp = NULL;
	i = 0;
	if (!top_a || !array)
	{
		write (2, "ERROR in parse_array function\n", 30);
		exit (1);
	}
	array = malloc (size);
	tmp = top_a;
	while (i < size && tmp != NULL)
	{
		array[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (array);
}
