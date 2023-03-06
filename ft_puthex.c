/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:55:41 by hachahbo          #+#    #+#             */
/*   Updated: 2022/12/29 19:11:06 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_put_hex(unsigned int num, char c)
{
	if (num >= 16)
		return (ft_put_hex(num / 16, c) + ft_put_hex(num % 16, c));
	if (c == 'X')
		return (ft_putchar("0123456789ABCDEF"[num]));
	else
		return (ft_putchar("0123456789abcdef"[num]));
}

int	ft_print_hex(long long num, const char c)
{
	return (ft_put_hex(num, c));
}
