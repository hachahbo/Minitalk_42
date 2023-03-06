/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:40:47 by hachahbo          #+#    #+#             */
/*   Updated: 2022/12/30 19:41:26 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print(char c, siginfo_t *t)
{
	write(1, &c, 1);
	if (c == '\0')
	{
		write(1, "\n", 1);
		usleep(500);
		kill(t->si_pid, SIGUSR2);
	}	
}

void	handler(int signal_type, siginfo_t *t, void *e)
{
	static int	cpid;
	static int	i;
	static char	c;

	(void)e;
	if (cpid != t->si_pid)
	{
		cpid = t->si_pid;
		write(1, "\n", 1);
		i = 0;
		c = 0;
	}
	if (signal_type == SIGUSR1)
		c = (c * 2) + 1;
	else if (signal_type == SIGUSR2)
		c = (c * 2);
	i++;
	if (i == 8)
	{
		print(c, t);
		i = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	action;

	(void)ac;
	(void)av;
	pid = getpid();
	ft_printf("THE PROCESS ID : %d\n", pid);
	action.sa_sigaction = (void *)handler;
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
}
