/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danevans <danevans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:43:32 by danevans          #+#    #+#             */
/*   Updated: 2024/04/29 01:44:05 by danevans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_int(long *stack, int num)
{
	int	i;
	int	temp;

	i = -1;
	temp = stack[0];
	while (++i < num)
	{
		if (stack[i] < temp)
			temp = stack[i];
	}
	return (temp);
}

int	min_int_next(long *stack, int num, int min_num)
{
	int	i;
	int	temp;

	i = -1;
	temp = INT_MAX;
	while (++i < num)
	{
		if (stack[i] < temp && stack[i] > min_num)
			temp = stack[i];
	}
	return (temp);
}

int	max_int(long *stack, int num)
{
	int	i;
	int	temp;

	i = -1;
	temp = stack[0];
	while (++i < num)
	{
		if (stack[i] > temp)
			temp = stack[i];
	}
	return (temp);
}

int	pre_max_int(long *stack, int num, int max_num)
{
	int	i;
	int	temp;

	i = -1;
	temp = INT_MIN;
	while (++i < num)
	{
		if (stack[i] > temp && stack[i] < max_num)
			temp = stack[i];
	}
	return (temp);
}

void	free_exit(t_data *data, char *container[])
{
	ft_cleaner(container);
	free(data->stack_a);
	free(data->stack_b);
}
