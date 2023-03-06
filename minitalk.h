/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:52:38 by hachahbo          #+#    #+#             */
/*   Updated: 2022/12/31 16:11:01 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <libc.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_atoi(char *c);

#endif