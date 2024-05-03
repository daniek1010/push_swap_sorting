/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danevans <danevans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:35:53 by danevans          #+#    #+#             */
/*   Updated: 2024/04/29 03:32:51 by danevans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(long *stack_a, int *numbers_a)
{
	int		i;
	long	temp;

	temp = stack_a[0];
	i = 0;
	while (i < *numbers_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[*numbers_a - 1] = temp;
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(long *stack_b, int *numbers_b)
{
	int		i;
	long	temp;

	temp = stack_b[0];
	i = 0;
	while (i < *numbers_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[*numbers_b - 1] = temp;
	ft_putstr_fd("rb\n", 1);
}

void	rotate_rr(long *stack_a, int *numbers_a, long *stack_b, int *numbers_b)
{
	int		i;
	long	temp;

	temp = stack_a[0];
	i = 0;
	while (i < *numbers_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[*numbers_a - 1] = temp;
	i = 0;
	temp = stack_b[0];
	while (i < *numbers_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[*numbers_b - 1] = temp;
	ft_putstr_fd("rr\n", 1);
}

int	is_sorted(long *stack, int num)
{
	int	i;

	i = -1;
	while (++i < num - 1)
	{
		if (stack[i] > stack[i + 1])
		{
			return (0);
		}
	}
	return (1);
}
