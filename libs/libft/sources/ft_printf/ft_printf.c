/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:06:54 by larcrist          #+#    #+#             */
/*   Updated: 2022/11/18 00:28:27 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_translate(char flag, va_list arg);

int	ft_printf(const char *str, ...)
{
	int		index;
	int		count;
	va_list	arg;

	index = 0;
	count = 0;
	va_start(arg, str);
	if (!str)
		return (-1);
	while (str[index] != '\0')
	{
		if (str[index] != '%')
			count += ft_putchar(str[index]);
		else
		{
			index++;
			count += ft_translate(str[index], arg);
		}
		index++;
	}
	va_end(arg);
	return (count);
}

static int	ft_translate(char flag, va_list arg)
{
	int	type_return;

	type_return = 0;
	if (flag == 'c')
		type_return = ft_putchar(va_arg(arg, int));
	else if (flag == 's')
		type_return = ft_putstr(va_arg(arg, char *));
	else if (flag == 'd' || flag == 'i')
		type_return = ft_putnbr(va_arg(arg, int));
	else if (flag == 'u')
		type_return = ft_putnbr_unsigned(va_arg(arg, int));
	else if (flag == 'x' || flag == 'X')
		type_return = ft_puthex(va_arg(arg, unsigned long int), flag);
	else if (flag == 'p')
		type_return = ft_putptr(va_arg(arg, unsigned long int));
	else if (flag == '%')
		return (ft_putchar('%'));
	return (type_return);
}
