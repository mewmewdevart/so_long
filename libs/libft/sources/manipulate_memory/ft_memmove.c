/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:18:11 by larcrist          #+#    #+#             */
/*   Updated: 2022/10/06 16:23:28 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*source;
	char	*destiny;
	size_t	index;

	source = (char *)src;
	destiny = (char *)dest;
	index = 0;
	if (source > destiny)
	{
		while (index < len)
		{
			destiny[index] = source[index];
			index++;
		}
	}
	else
	{
		while (index != len)
		{
			destiny[len - index - 1] = source[len - index - 1];
			index++;
		}
	}
	return (dest);
}
