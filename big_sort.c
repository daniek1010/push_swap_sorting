/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danevans <danevans@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:02:11 by danevans          #+#    #+#             */
/*   Updated: 2024/05/02 10:47:56 by danevans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	chunk_sort_b(t_data *data)
{
	int		max_numb;
	int		max_index;
	int		pre_max;
	int		pre_max_index;

	while (data->num_b)
	{
		max_numb = max_int(data->stack_b, data->num_b);
		max_index = get_index_max(data->stack_b, data->num_b, max_numb);
		pre_max = pre_max_int(data->stack_b, data->num_b, max_numb);
		pre_max_index = get_index_max(data->stack_b, data->num_b, pre_max);
		if (max_index > data->num_b / 2)
			max_index = data->num_b - max_index;
		if (pre_max_index > data->num_b / 2)
			pre_max_index = data->num_b - pre_max_index;
		if (max_index < pre_max_index)
			sorting_b(data, max_numb, pre_max);
		else
			sorting_b(data, pre_max, max_numb);
		if (data->stack_a[0] > data->stack_a[1])
			swap_a(data->stack_a, &data->num_a);
	}
}

static void	chunk_sort_a(t_data *data, int chunk)
{
	int		i;
	int		min;
	int		index;

	min = min_int(data->stack_a, data->num_a);
	while (data->num_a)
	{
		i = -1;
		while (++i < chunk)
		{
			min = min_int_next(data->stack_a, data->num_a, min);
			if (i == chunk / 2)
				data->mid_chunk = min;
		}
		i = -1;
		while (++i < chunk)
		{
			index = get_index_min(data->stack_a, data->size, min);
			check_position_sort_a(data, data->stack_a[index]);
			if (data->stack_b[0] < data->mid_chunk)
				rotate_b(data->stack_b, &data->num_b);
		}
	}
	chunk_sort_b(data);
}

void	big_sort(t_data *data)
{
	if (data->num_a <= 120)
		chunk_sort_a(data, 20);
	else
		chunk_sort_a(data, 50);
}

void	data_init(t_data *data, char *container[])
{
	data->stack_a = valid_create(data, container);
	data->stack_b = valid_create(data, container);
	data->num_a = data->size;
	data->num_b = 0;
	data->top = -1;
	push_stack(container, data);
}
