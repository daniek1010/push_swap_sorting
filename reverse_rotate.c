/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danevans <danevans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:35:36 by danevans          #+#    #+#             */
/*   Updated: 2024/04/28 23:53:08 by danevans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(long *stack_a, int *numbers_a)
{
	int		i;
	long	temp;

	temp = stack_a[*numbers_a - 1];
	i = *numbers_a - 1;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = temp;
	ft_putstr_fd("rra\n", 1);
}

void	reverse_b(long *stack_b, int *numbers_b)
{
	int		i;
	long	temp;

	temp = stack_b[*numbers_b - 1];
	i = *numbers_b - 1;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = temp;
	ft_putstr_fd("rrb\n", 1);
}

void	reverse_rr(long *stack_a, int *numbers_a, long *stack_b, int *numbers_b)
{
	int		i;
	long	temp;

	temp = stack_a[*numbers_a - 1];
	i = *numbers_a - 1;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = temp;
	i = *numbers_b - 1;
	temp = stack_b[*numbers_b - 1];
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = temp;
	ft_putstr_fd("rrr\n", 1);
}

void	checker2_swap(t_data *data)
{
	push_a(data->stack_a, &data->num_a, data->stack_b, &data->num_b);
	swap_a(data->stack_a, &data->num_a);
	reverse_a(data->stack_a, &data->num_a);
}

void	checker2_rotate(t_data *data)
{
	push_a(data->stack_a, &data->num_a, data->stack_b, &data->num_b);
	rotate_a(data->stack_a, &data->num_a);
	rotate_a(data->stack_a, &data->num_a);
}
