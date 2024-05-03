/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danevans <danevans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:03:06 by danevans          #+#    #+#             */
/*   Updated: 2024/04/29 01:51:36 by danevans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_min(long *stack, int size, int num)
{
	int		i;
	int		temp;

	i = -1;
	while (++i < size)
	{
		if (stack[i] <= num)
		{
			temp = i;
			return (temp);
		}
	}
	return (-1);
}

int	get_index_max(long *stack, int size, int num)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (stack[i] == num)
		{
			return (i);
		}
	}
	return (-1);
}

void	check_position_sort_a(t_data *data, long num)
{
	int		index;

	index = get_index_min(data->stack_a, data->num_a, num);
	if (index <= data->num_a / 2)
	{
		while (data->stack_a[0] != num)
			rotate_a(data->stack_a, &data->num_a);
	}
	else
	{
		while (data->stack_a[0] != num)
			reverse_a(data->stack_a, &data->num_a);
	}
	push_b(data->stack_a, &data->num_a, data->stack_b, &data->num_b);
}

void	check_position_sort_b(long *stack, int size, long num)
{
	int		index;

	index = get_index_max(stack, size, num);
	if (index == -1)
		return ;
	if (index <= (size) / 2)
	{
		while (stack[0] != num)
			rotate_b(stack, &size);
	}
	else
	{
		while (stack[0] != num)
			reverse_b(stack, &size);
	}
}

void	swap_rev_rot_helper(long *stack, int num, int i)
{
	if (i == 1)
	{
		swap_a(stack, &num);
		reverse_a(stack, &num);
	}
	else if (i == 2)
	{
		swap_a(stack, &num);
		rotate_a(stack, &num);
	}
}
