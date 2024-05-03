/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danevans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:43:06 by danevans          #+#    #+#             */
/*   Updated: 2023/06/06 13:52:26 by danevans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destcast;
	const char	*srccast;
	size_t		i;

	destcast = (char *)dest;
	srccast = (const char *)src;
	if (srccast < destcast)
	{
		i = n;
		while (i > 0)
		{
			destcast[i - 1] = srccast[i - 1];
			i--;
		}
	}
	else
		ft_memcpy(destcast, srccast, n);
	return (dest);
}
