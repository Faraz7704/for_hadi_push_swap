/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_normally.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:22:47 by hakaddou          #+#    #+#             */
/*   Updated: 2022/04/26 18:34:01 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void swap (int *a, int *b)
{
    int  temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

void slection_sort(int *a, int size)
{
    int i;
    int j;
    i = 0;
    int temp;
    
    i = 1;
    while(i < size)
    { 
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
        i++;
    }
}

int	*sort_array (t_stack *top_a)
{
	int		size;
	t_stack	*tmp;
	int		*array;
	int		i;

	i = 0;
	array = NULL;
	tmp = NULL;
	tmp = top_a;
	size = get_size(tmp);
	array = malloc (size * sizeof (int));
	tmp = top_a;
	while (i < size && tmp != NULL)
	{
		array[i] = tmp->content;
		printf ("array[%d] is %d\n", i, array[i]);
		i++;
		tmp = tmp->next;
	}
	return (array);
}

int is_sorted (int *array, t_stack *top_a)
{
	int		i;
	t_stack	*tmp;
	int		d;

	d = 0;
	i = 0;
	tmp = NULL;
	if (!array || !top_a)
	{
		write (2, "ERROR in is_sorted fun\n", 23);
		exit (1);
	}
	tmp = top_a;
	while (tmp != NULL)
	{
		if (tmp->content - array[d] == 0)
			i++;
		d++;
		printf ("array[i] is %d and stack is %d and is %d\n", array[d], tmp->content, i);
		tmp = tmp->next;
	}
	if (i > 0)
		return (0);
	else
		return (1);
}