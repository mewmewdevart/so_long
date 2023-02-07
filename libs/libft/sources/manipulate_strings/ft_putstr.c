/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:03:08 by larcrist          #+#    #+#             */
/*   Updated: 2022/11/17 15:09:15 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_putstr(char *str)
{
	int	index;

	index = 0;
	if (!str)
		index = write(1, "(null)", 6);
	else
	{
		while (str[index] != '\0')
		{
			write (1, &str[index], 1);
			index++;
		}
	}
	return (index);
}
