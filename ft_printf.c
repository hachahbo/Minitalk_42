/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:06:26 by hachahbo          #+#    #+#             */
/*   Updated: 2022/12/15 11:11:23 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_the_char(char c, va_list *arg_list)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*arg_list, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*arg_list, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*arg_list, int)));
	else if (c == 'u')
		return (ft_putnbr(va_arg(*arg_list, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(*arg_list, unsigned int), c));
	else if (c == 'p')
		return (ft_putptr(va_arg(*arg_list, unsigned long int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (ft_putchar(c));
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_list;
	int		i;
	int		len;
	int		r;

	r = write(1, "", 0);
	if (r < 0)
		return (-1);
	va_start(arg_list, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				break ;
			len += ft_check_the_char(str[++i], &arg_list);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(arg_list);
	return (len);
}
