/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:32:21 by larcrist          #+#    #+#             */
/*   Updated: 2022/10/13 23:32:23 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_itoa_neg(int n);
static int	ft_itoa_len(int n);

char	*ft_itoa(int n)
{
	char			*str;
	int				signal;
	int				len;
	unsigned int	num;

	signal = ft_itoa_neg(n);
	num = n * signal;
	len = ft_itoa_len(num);
	if (signal == -1)
		len++;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	len--;
	if (!num)
		str[0] = '0';
	if (signal == -1)
		str[0] = '-';
	while (num)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

static int	ft_itoa_len(int n)
{
	if (!(n / 10))
	{
		return (1);
	}
	return (1 + ft_itoa_len(n / 10));
}

static int	ft_itoa_neg(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (1);
}
