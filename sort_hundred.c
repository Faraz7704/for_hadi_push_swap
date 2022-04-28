/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:05:13 by hakaddou          #+#    #+#             */
/*   Updated: 2022/04/27 01:35:25 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_dividor(t_stack *top_a)
{
	if (get_size(top_a) <= 5)
		return (1);
	else if (get_size (top_a) >= 6 && get_size(top_a) <= 10)
		return (2);
	else if (get_size (top_a) >= 11 && get_size(top_a) <= 20)
		return (3);
	else if (get_size (top_a) >= 21 && get_size(top_a) <= 50)
		return (5);
	else if (get_size (top_a) >= 51 && get_size(top_a) <= 100)
		return (7);
	else if (get_size (top_a) >= 101 && get_size(top_a) <= 200)
		return (14);
	else if (get_size (top_a) >= 201 && get_size(top_a) <= 600)
		return (20);
	else if (get_size (top_a) >= 600 && get_size(top_a) <= 3000)
		return (40);
	else
		return (50);
}

void	phase_one (t_stack **top_a, t_stack **top_b)
{
	int n;

	while (get_size(*top_a) != 0)
	{
		n = phase_two(top_a, top_b);
		untill_max_is_top_n(top_b, n);
	}
}

int	phase_two(t_stack **top_a, t_stack **top_b)
{
	int	size;
	int	n;

	n = get_dividor(*top_a);
	size = get_size(*top_a) / n;
	if (size == 0)
	{
		while (get_size(*top_a) != 0)
			push_to_b(top_b, top_a);
	}
	while (size > 0)
	{
		push_to_b (top_b, top_a);
		size--;
	}
	return (n);
}

void	untill_min_is_top_n(t_stack **top_b, int n)
{
	if (get_index(*top_b, find_min_n_times(*top_b, n)) < n / 2)
		while (get_index(*top_b, find_min_n_times(*top_b, n)) != 0)
			rotate_b(top_b);
	else if (get_index(*top_b, find_min_n_times(*top_b, n)) >= n / 2)
		while (get_index(*top_b, find_min_n_times(*top_b, n)) != 0)
			reverse_rotate_b(top_b);
}

void	untill_max_is_top_n(t_stack **top_b, int n)
{
	if (get_index(*top_b, find_max_n_times(*top_b, n)) < n / 2)
		while (get_index(*top_b, find_max_n_times(*top_b, n)) != 0)
			rotate_b(top_b);
	else if (get_index(*top_b, find_max_n_times(*top_b, n)) >= n / 2)
		while (get_index(*top_b, find_max_n_times(*top_b, n)) != 0)
			reverse_rotate_b(top_b);
}

int	find_min_n_times (t_stack *top, int n)
{
	int	min;
	int	i;

	i = 0;
	if (!top)
	{
		write (2, "ERROR in check_f_n_t function\n", 30);
		exit (1);
	}
	min = INT_MAX;
	while (top != NULL && i < n)
	{
		if (min > top->content)
			min = top->content;
		top = top->next;
		i++;
	}
	return (min);
}

int	find_max_n_times (t_stack *top, int n)
{
	int	max;
	int	i;

	i = 0;
	if (!top)
	{
		write (2, "ERROR in get_max function\n", 26);
		exit (1);
	}
	max = INT_MIN;
	while (top != NULL && i < n)
	{
		if (max < top->content)
			max = top->content;
		top = top->next;
	}
	return (max);
}