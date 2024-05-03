/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danevans <danevans@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:22:23 by danevans          #+#    #+#             */
/*   Updated: 2024/05/02 10:37:37 by danevans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	param_check(int argc, char **argv)
{
	int		i;
	int		j;
	char	*holder;

	i = 0;
	while (++i < argc)
	{
		holder = argv[i];
		j = 0;
		while (holder[j] != '\0')
		{
			if ((holder[j] < 48 || holder[j] > 57) && holder[j] != 32)
			{
				if (holder[j] != 45)
					error();
				if ((holder[j] == 45) && ((holder[j + 1] == 45 || holder[j + 1]
							== '\0') || ((holder[j - 1] >= '0')
							&& (holder[j - 1] <= '9'))))
					error();
				if (holder[j] == 32 && holder[j + 1] == 32)
					error();
			}
			j++;
		}
	}
}

char	**check_size(int argc, char *argv[])
{
	int		i;
	char	*temp;
	char	*str;
	char	**container;

	param_check(argc, argv);
	i = 0;
	str = ft_calloc(1, 1);
	while (++i < argc)
	{
		temp = ft_strjoin(str, argv[i]);
		free(str);
		str = temp;
		if (temp != NULL)
		{
			temp = ft_strjoin(str, " ");
			free(str);
			str = temp;
		}
	}
	container = ft_split(str, ' ');
	free(str);
	return (container);
}

int	push_stack(char *container[], t_data *data)
{
	int		i;
	int		k;
	long	num;

	i = 0;
	while (container[i] != NULL)
	{
		k = data->top + 1;
		num = ft_atol(container[i]);
		if (max_min(num))
		{
			ft_putstr_fd("Error\n", 2);
			free(data->stack_a);
			exit (1);
		}
		if (isduplicate(num, k, data->stack_a))
		{
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
		data->stack_a[++(data->top)] = num;
		i++;
	}
	return (0);
}

int	isduplicate(int num, int k, long stack[])
{
	int	i;

	i = 0;
	while (i < k)
	{
		if (stack[i] == num)
			return (1);
		i++;
	}
	return (0);
}

long	*valid_create(t_data *data, char *container[])
{
	long	*stack;
	int		i;

	i = 0;
	while (container[i] != NULL)
		i++;
	data->size = i;
	stack = (long *)(malloc (sizeof(long) * (i) + 1));
	if (stack == NULL)
		return (NULL);
	return (stack);
}
