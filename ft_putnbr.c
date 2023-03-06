/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:06:57 by hachahbo          #+#    #+#             */
/*   Updated: 2022/11/12 15:47:46 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nb)
{
	if (nb < 0)
		return (ft_putchar('-') + ft_putnbr(-nb));
	else if (nb < 10)
		return (ft_putchar(nb + '0'));
	else
		return (ft_putnbr(nb / 10) + ft_putchar((nb % 10) + '0'));
}
