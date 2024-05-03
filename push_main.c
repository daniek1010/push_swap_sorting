/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danevans <danevans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:20:47 by danevans          #+#    #+#             */
/*   Updated: 2024/04/29 03:31:34 by danevans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	char	**container;

	if ((argc == 1) || (argv[1][0] == '\0'))
		error();
	container = check_size(argc, argv);
	data_init(&data, container);
	if (!is_sorted(data.stack_a, data.size))
	{
		if (data.num_a == 2)
		{
			if (data.stack_a[0] > data.stack_a[1])
				swap_a(data.stack_a, &data.num_a);
		}
		else if (data.num_a == 3)
			small_sort(data.stack_a, data.num_a);
		else if ((data.num_a == 4) || (data.num_a == 5))
			five_sort(&data);
		else if (data.num_a > 5)
			big_sort(&data);
	}
	free_exit(&data, container);
	return (0);
}
