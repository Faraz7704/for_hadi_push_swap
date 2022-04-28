/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 06:05:57 by hakaddou          #+#    #+#             */
/*   Updated: 2022/04/24 09:08:06 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*tmp;
	int		i;

	if (!s || len == 0 || start > ft_strlen(s))
	{
		write (1, "substr problem\n", 15);
		exit (1);
	}
	i = 0;
	if (ft_strlen(s) < len)
		tmp = (char *)ft_calloc(ft_strlen(&s[start] + 1), 1);
	else
		tmp = (char *)ft_calloc(len + 1, 1);
	if (!tmp)
		return (0);
	while (start < ft_strlen(s) && i < len)
		tmp[i++] = s[start++];
	tmp[i] = '\0';
	return (tmp);
}

void	print_stack(t_stack *top, char c)
{
	t_stack	*tmp;

	if (!top)
		return ;
	tmp = top;
	while (tmp != NULL)
	{
		printf ("top_%c is %d at index %d\n", c, tmp->content, tmp->index);
		tmp = tmp->next;
	}
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t n, size_t size)
{
	char		*tmp;

	if (n == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	tmp = malloc(n * size);
	if (tmp == NULL)
		return (tmp);
	ft_bzero(tmp, size * n);
	return (tmp);
}
