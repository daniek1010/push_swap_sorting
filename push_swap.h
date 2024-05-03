/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danevans <danevans@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 08:27:10 by danevans          #+#    #+#             */
/*   Updated: 2024/05/02 10:38:36 by danevans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <string.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_data
{
	long	*stack_a;
	long	*stack_b;
	int		num_a;
	int		num_b;
	int		mid_chunk;
	int		size;
	int		top;
}	t_data;

/* param.c */
char	**check_size(int argc, char *argv[]);
void	param_check(int argc, char **argv);
int		isduplicate(int num, int k, long stack[]);
int		push_stack(char *container[], t_data *data);
long	*valid_create(t_data *data, char *container[]);

/* swapush.c */
void	swap_a(long *stack_a, int *num_a);
void	swap_b(long *stack_b, int *num_b);
void	swap_ss(long *stack_a, int *num_a, long *stack_b, int *num_b);
int		push_a(long *stack_a, int *num_a, long *stack_b, int *num_b);
int		push_b(long *stack_a, int *num_a, long *stack_b, int *num_b);

/* rotate.c */
void	rotate_a(long *stack_a, int *num_a);
void	rotate_b(long *stack_b, int *num_b);
void	rotate_rr(long *stack_a, int *num_a, long *stack_b, int *num_b);

/* reverse_rotate.c*/
void	reverse_a(long *stack_a, int *num_a);
void	reverse_b(long *stack_b, int *num_b);
void	reverse_rr(long *stack_a, int *num_a, long *stack_b, int *num_b);
void	checker2_swap(t_data *data);
void	checker2_rotate(t_data *data);

/* big_sort.c && small_sort.c */
int		small_sort(long *stack, int num);
int		is_sorted(long *stack, int num);
void	five_sort(t_data *data);
void	big_sort(t_data *data);
void	data_init(t_data *data, char *container[]);

/* utils.c*/
int		max_min(long number);
long	ft_atol(const char *nptr);
void	ft_cleaner(char *str[]);
void	error(void);
void	sorting_b(t_data *data, int max, int pre_max);

/* utils1.c*/
int		min_int(long *stack, int num);
int		max_int(long *stack, int num);
int		min_int_next(long *stack, int num, int min_num);
int		pre_max_int(long *stack, int num, int max_num);
void	free_exit(t_data *data, char *container[]);

/* utils2.c*/
int		get_index_min(long *stack, int size, int num);
int		get_index_max(long *stack, int size, int num);
void	check_position_sort_a(t_data *data, long num);
void	check_position_sort_b(long *stack, int size, long num);
void	swap_rev_rot_helper(long *stack, int num, int i);

#endif