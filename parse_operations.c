/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:25:49 by hakaddou          #+#    #+#             */
/*   Updated: 2022/04/25 15:40:20 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	untill_max_is_last(t_stack **top)
{
	if (get_index(*top, get_max(*top)) < get_size(*top) / 2)
		while (get_index(*top, get_max(*top)) != get_size(*top) - 1)
			rotate_a(top);
	else if (get_index(*top, get_max(*top)) >= get_size(*top) / 2)
		while (get_index(*top, get_max(*top)) != get_size(*top) - 1)
			reverse_rotate_a(top);
}

void	untill_max_is_top(t_stack **top)
{
	if (get_index(*top, get_max(*top)) < get_size(*top) / 2)
		while (get_index(*top, get_max(*top)) != 0)
			rotate_a(top);
	else if (get_index(*top, get_max(*top)) >= get_size(*top) / 2)
		while (get_index(*top, get_max(*top)) != 0)
			reverse_rotate_a(top);
}

void	untill_min_is_top(t_stack **top)
{
	if (get_index(*top, get_min(*top)) < get_size(*top) / 2)
		while (get_index(*top, get_min(*top)) != 0)
			rotate_a(top);
	else if (get_index(*top, get_min(*top)) >= get_size(*top) / 2)
		while (get_index(*top, get_min(*top)) != 0)
			reverse_rotate_a(top);
}

void	sort_five(t_stack **top_a, t_stack **top_b)
{
	untill_min_is_top(top_a);
	push_to_b(top_b, top_a);
	sort_four(top_a, top_b);
	push_to_a(top_a, top_b);
}

void	sort_total(t_stack **top_a, t_stack **top_b)
{
	while (get_size(*top_a) != 5)
	{
		untill_min_is_top(top_a);
		push_to_b(top_b, top_a);
	}
	sort_five(top_a, top_b);
	while (get_size(*top_b) != 0)
		push_to_a(top_a, top_b);
}

void	parse_operations(t_stack **top_a, t_stack **top_b)
{
	int	size;

	size = get_size(*top_a);
	if (size == 2)
		sort_two (*top_a);
	else if (size == 3)
		sort_three (top_a);
	else if (size == 4)
		sort_four(top_a, top_b);
	else if (size == 5)
		sort_five (top_a, top_b);
	else
		sort_total (top_a, top_b);
}
