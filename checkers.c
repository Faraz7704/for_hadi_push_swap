/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:47:12 by hakaddou          #+#    #+#             */
/*   Updated: 2022/04/24 17:57:18 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *top)
{
	t_stack	*tmp;

	tmp = NULL;
	while (top != NULL)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_check_dups(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		ft_atoi (av[i]);
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp (av[i], av[j]) == 0)
			{
				write (2, "ERROR\n", 6);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

void	check_sum(unsigned long sum, int sign, const char *str)
{
	if (sum > 2147483647 && sign == 1)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	else if (sum > 2147483648 && sign == -1)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	else if (*str)
	{
		write (2, "ERROR\n", 6);
		exit (1);
	}
}

int	ft_atoi(const char *str)
{
	unsigned long	sum;
	int				sign;

	sum = 0;
	sign = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + *str - '0';
		str++;
	}
	check_sum (sum, sign, str);
	return (sum * sign);
}
