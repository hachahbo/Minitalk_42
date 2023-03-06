/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:26:23 by hachahbo          #+#    #+#             */
/*   Updated: 2022/12/31 16:13:25 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	bits;

	bits = 8;
	while (bits--)
	{
		if (c & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c <<= 1;
		usleep(300);
	}
}

int	main(int arc, char *arv[])
{
	char	*str;
	int		pid;

	if (arc == 3)
	{
		pid = ft_atoi(arv[1]);
		str = arv[2];
		while (*str)
		{
			send_char(pid, *str);
			str++;
		}
		send_char(pid, 0);
	}
}
