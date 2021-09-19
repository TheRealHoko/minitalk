/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:53:34 by jzeybel           #+#    #+#             */
/*   Updated: 2021/09/19 15:48:01 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

long	ft_atol(char *s)
{
	int	i;
	long	res;

	i = -1;
	res = 0;
	while (s[++i] != 0)
		res = res * 10 + (s[i] - 48);
	return (res);
}

void	ft_sendchar(unsigned char c, pid_t pid)
{
	int	i;

	i = 8;
	while (i)
	{
		if ((c >> --i) % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
	}
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

void	ft_handler(int signo)
{

	if (signo == SIGUSR2)
		bitin(0);
	else if (signo == SIGUSR1)
		bitin(1);
}

void	bitin(int bit)
{
	static unsigned char c = 0;
	static int	i = 0;

	if (i == 8)
	{
		write(1, &c, 1);
		i = 1;
		c = bit;
	}
	else
	{
		c <<= 1 | bit;
		i++;
	}
}
