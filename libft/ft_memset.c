/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danevans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 01:14:12 by danevans          #+#    #+#             */
/*   Updated: 2023/06/12 19:24:58 by danevans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cast;
	size_t			i;

	cast = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		cast[i] = c;
		i++;
	}
	return (s);
}
