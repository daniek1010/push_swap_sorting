/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danevans <danevans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:38:27 by danevans          #+#    #+#             */
/*   Updated: 2024/04/29 00:07:09 by danevans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_min(long number)
{
	if ((number <= -2147483648L) || (number >= 2147483647L))
		return (1);
	return (0);
}

void	ft_cleaner(char *str[])
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

long	ft_atol(const char *nptr)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return ((result * sign));
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	sorting_b(t_data *data, int max, int pre_max)
{
	check_position_sort_b(data->stack_b, data->num_b, max);
	push_a(data->stack_a, &data->num_a, data->stack_b, &data->num_b);
	check_position_sort_b(data->stack_b, data->num_b, pre_max);
	push_a(data->stack_a, &data->num_a, data->stack_b, &data->num_b);
}
