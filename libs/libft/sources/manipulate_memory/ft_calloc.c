/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:30:03 by coder             #+#    #+#             */
/*   Updated: 2022/10/07 13:46:12 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	if (nitems * size == 0 || nitems > 2147483647 / size)
		return (NULL);
	ptr = malloc(nitems * size);
	if (!ptr)
	{
		return (NULL);
	}
	ft_bzero(ptr, nitems * size);
	return (ptr);
}
