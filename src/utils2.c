/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:53:34 by jzeybel           #+#    #+#             */
/*   Updated: 2021/10/26 18:16:50 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

long	ft_atol(char *s)
{
	int		i;
	long	res;

	i = -1;
	res = 0;
	while (s[++i] != 0)
		res = res * 10 + (s[i] - 48);
	return (res);
}

void	ft_sendchar(unsigned char c, pid_t pid)
{
	int		i;
	char	d;

	i = 8;
	d = 0;
	while (i)
	{
		if ((c >> --i) % 2)
		{
			kill(pid, SIGUSR1);
			d = d << 1 | 1;
		}
		else
		{
			kill(pid, SIGUSR2);
			d = d << 1 | 0;
		}
		usleep(7000);
	}
	write(1, &d, 1);
}

void	ft_sendmsg(char *s, pid_t pid)
{
	while (*s)
	{
		ft_sendchar(*s, pid);
		s++;
	}
	ft_sendchar('\n', pid);
}

void	ft_handler(int signo, siginfo_t *info, void *ctx)
{
	(void)ctx;
	if (signo == SIGUSR2)
	{
		ft_converter(0);
		kill(info->si_pid, SIGUSR1);
	}
	else if (signo == SIGUSR1)
	{
		ft_converter(1);
		kill(info->si_pid, SIGUSR2);
	}
}

void	ft_converter(int bit)
{
	static unsigned char	c = 0;
	static int				i = 0;

	c = c << 1 | bit;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}
