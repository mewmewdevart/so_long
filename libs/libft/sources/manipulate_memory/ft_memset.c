/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:42:53 by larcrist          #+#    #+#             */
/*   Updated: 2022/10/04 21:42:56 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			index;
	unsigned char	*ptr;

	ptr = str;
	index = 0;
	while (index < len)
	{
		ptr[index] = (unsigned char)c;
		index++;
	}
	return (str);
}
