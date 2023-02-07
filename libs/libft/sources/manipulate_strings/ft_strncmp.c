/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 03:03:42 by larcrist          #+#    #+#             */
/*   Updated: 2022/09/11 03:12:34 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0)
	{
		return (0);
	}
	while ((s1[index] != '\0' && s2[index] != '\0')
		&& s1[index] == s2[index] && index < n - 1)
	{
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
