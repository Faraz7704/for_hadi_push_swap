/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 05:24:01 by hakaddou          #+#    #+#             */
/*   Updated: 2022/04/26 23:47:04 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// important things to remeber :
// when we input 1 negative by it's own it returns a 0 example "-"

int	main(int ac, char **av)
{
	t_stack	*top_a;
	t_stack	*tmp;
	t_stack	*top_b;

	top_b = NULL;
	top_a = NULL;
	check (ac, av);
	top_a = parse_stack (top_a, ac, av);
	tmp = top_a;
	// print_stack (tmp, 'a');
	// push_quart(&top_a, &top_b, 'a');
	// print_stack(tmp, 'b');
	// printf ("before sort:\n%d\n", is_sorted(array, tmp));
	phase_one(&top_a, &top_b);
	// slection_sort(array, get_size(top_a));
	// printf ("after sort:\n%d\n", is_sorted(array, tmp));
	// parse_operations (&top_a, &top_b);
	// print_stack(top_a, 'a');
	ft_free (top_a);
	ft_free (top_b);
}

/*

make re && rm *.o && ./push_swap {100..1}

make re && rm *.o && valgrind --leak-check=full ./push_swap 


python visualizer:

make re && rm *.o && /usr/bin/python3 python_visualizer.py `ruby -e "puts (0..100).to_a.shuffle.join(' ')"`
 
*/