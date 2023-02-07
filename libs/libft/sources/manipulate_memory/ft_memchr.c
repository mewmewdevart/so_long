/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 03:03:42 by larcrist          #+#    #+#             */
/*   Updated: 2022/10/05 03:12:34 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			index;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	index = 0;
	while (index < n)
	{
		if (str[index] == ch)
		{
			return ((void *)s + index);
		}
		index++;
	}
	return (NULL);
}
