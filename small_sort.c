/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danevans <danevans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:54:01 by danevans          #+#    #+#             */
/*   Updated: 2024/04/29 03:33:24 by danevans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_position1(t_data *data)
{
	if (data->stack_b[0] < data->stack_a[0])
		push_a(data->stack_a, &data->num_a, data->stack_b, &data->num_b);
	else if ((data->stack_b[0] > data->stack_a[0])
		&& (data->stack_b[0] < data->stack_a[1]))
	{
		push_a(data->stack_a, &data->num_a, data->stack_b, &data->num_b);
		swap_a(data->stack_a, &data->num_a);
	}
	else if ((data->stack_b[0] > data->stack_a[1])
		&& (data->stack_b[0] < data->stack_a[2]))
	{
		rotate_a(data->stack_a, &data->num_a);
		push_a(data->stack_a, &data->num_a, data->stack_b, &data->num_b);
		swap_a(data->stack_a, &data->num_a);
		reverse_a(data->stack_a, &data->num_a);
	}
	else if (data->stack_b[0] > data->stack_a[2])
	{
		push_a(data->stack_a, &data->num_a, data->stack_b, &data->num_b);
		rotate_a(data->stack_a, &data->num_a);
	}
}

static void	check_position2(t_data *data)
{
	if (data->stack_b[0] < data->stack_a[0])
		push_a(data->stack_a, &data->num_a, data->stack_b, &data->num_b);
	else if ((data->stack_b[0] > data->stack_a[0])
		&& (data->stack_b[0] < data->stack_a[1]))
	{
		push_a(data->stack_a, &data->num_a, data->stack_b, &data->num_b);
		swap_a(data->stack_a, &data->num_a);
	}
	else if ((data->stack_b[0] > data->stack_a[1])
		&& (data->stack_b[0] < data->stack_a[2]))
	{
		rotate_a(data->stack_a, &data->num_a);
		checker2_swap(data);
	}
	else if ((data->stack_b[0] > data->stack_a[2])
		&& (data->stack_b[0] < data->stack_a[3]))
	{
		reverse_a(data->stack_a, &data->num_a);
		checker2_rotate(data);
	}
	else if (data->stack_b[0] > data->stack_a[3])
	{
		push_a(data->stack_a, &data->num_a, data->stack_b, &data->num_b);
		rotate_a(data->stack_a, &data->num_a);
	}
}

static	int	ft_sorted(long *stack)
{
	if (stack[0] < stack[1] && stack[1] < stack[2])
		return (1);
	return (0);
}

int	small_sort(long *stack, int num)
{
	if (ft_sorted(stack) == 1)
		return (0);
	else
	{
		if (stack[0] > stack[1]
			&& stack[1] > stack[2])
			swap_rev_rot_helper(stack, num, 1);
		else if (stack[1] > stack[0])
		{
			if (stack[0] < stack[2])
				swap_rev_rot_helper(stack, num, 2);
			else if (stack[0] > stack[2])
				reverse_a(stack, &num);
		}
		else if (stack[1] < stack[0])
		{
			if (stack[0] < stack[2])
				swap_a(stack, &num);
			if (stack[0] > stack[2])
				rotate_a(stack, &num);
		}
	}
	return (0);
}

void	five_sort(t_data *data)
{
	if (data->num_a == 4)
	{
		push_b(data->stack_a, &data->num_a, data->stack_b, &data->num_b);
		small_sort(data->stack_a, data->num_a);
		check_position1(data);
	}
	else
	{
		push_b(data->stack_a, &data->num_a, data->stack_b, &data->num_b);
		push_b(data->stack_a, &data->num_a, data->stack_b, &data->num_b);
		small_sort(data->stack_a, data->num_a);
		check_position1(data);
		check_position2(data);
	}
}
