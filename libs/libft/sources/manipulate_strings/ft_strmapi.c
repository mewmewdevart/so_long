/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:51:56 by coder             #+#    #+#             */
/*   Updated: 2022/10/17 00:02:30 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	indice;
	unsigned int	length;
	char			*str;

	length = ft_strlen(s);
	str = (char *)ft_calloc(length + 1, sizeof(char));
	if (!str)
		return (0);
	indice = 0;
	while (s[indice] != '\0')
	{
		str[indice] = (*f)(indice, s[indice]);
		indice++;
	}
	return (str);
}
