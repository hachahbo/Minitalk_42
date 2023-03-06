/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:55:41 by hachahbo          #+#    #+#             */
/*   Updated: 2022/11/12 15:48:14 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printptr(unsigned long int num)
{
	if (num >= 16)
		return (ft_printptr(num / 16) + ft_printptr(num % 16));
	return (ft_putchar("0123456789abcdef"[num]));
}

int	ft_putptr(size_t num)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	return (len + ft_printptr(num));
}
