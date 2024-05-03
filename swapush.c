/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danevans <danevans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:46:14 by danevans          #+#    #+#             */
/*   Updated: 2024/04/24 14:58:20 by danevans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(long *stack_a, int *num_a)
{
	long	temp;

	if (*num_a > 1)
	{
		temp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp;
	}
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(long *stack_b, int *num_b)
{
	long	temp;

	if (*num_b > 1)
	{
		temp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = temp;
	}
	ft_putstr_fd("sb\n", 1);
}

void	swap_ss(long *stack_a, int *num_a, long *stack_b, int *num_b)
{
	long	temp_sa;
	long	temp_sb;

	if ((*num_a > 1) && (*num_b > 1))
	{
		temp_sb = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = temp_sb;
		temp_sa = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp_sa;
	}
	ft_putstr_fd("ss\n", 1);
}

int	push_a(long *stack_a, int *num_a, long *stack_b, int *num_b)
{
	int	i;

	if ((*num_b) == 0)
		return (0);
	(*num_a)++;
	i = (*num_a) - 1;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_b[0];
	i = 0;
	(*num_b)--;
	while (*num_b > i)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	if (*num_b == 0)
		stack_b = NULL;
	ft_putstr_fd("pa\n", 1);
	return (0);
}

int	push_b(long *stack_a, int *num_a, long *stack_b, int *num_b)
{
	int	i;

	if ((*num_a) == 0)
		return (0);
	(*num_b)++;
	i = (*num_b) - 1;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_a[0];
	i = 0;
	(*num_a)--;
	while (*num_a > i)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	if (*num_a == 0)
		stack_a = NULL;
	ft_putstr_fd("pb\n", 1);
	return (0);
}
