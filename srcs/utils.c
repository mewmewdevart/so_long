/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:47:39 by larcrist          #+#    #+#             */
/*   Updated: 2023/02/25 19:27:27 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Compares the string pointed to, by str1 to the string pointed to by str2
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// Locate all ocurrence of the character in string
size_t	ft_strchr_all_ocurrences(char *str, char ch)
{
	size_t	count;
	char	*ptr;

	count = 0;
	ptr = ft_strchr(str, ch);
	while (ptr != NULL)
	{
		ptr = ft_strchr(ptr + 1, ch);
		count++;
	}
	return (count);
}
