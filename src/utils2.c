/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:53:34 by jzeybel           #+#    #+#             */
/*   Updated: 2021/09/15 19:24:56 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	t_bit	g_bit;

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

void	ft_sendchar(unsigned char s, pid_t pid)
{
	int	i;

	i = 8;
	while (i)
	{
		if (!((s >> --i) % 2))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
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

void	ft_handler(int signo, siginfo_t *info, void *ctx)
{
	(void)ctx;
	if (signo == SIGUSR1)
	{
		g_bit.bitcount++;
		convert_char(0, info);
	}
	else if (signo == SIGUSR2)
	{
		g_bit.bitcount++;
		convert_char(1, info);
	}
}

void	set_global()
{
	g_bit.bitcount = 0;
	g_bit.c = 0;
	g_bit.bitstr = malloc(9);
	g_bit.bitstr[8] = 0;
	if (!g_bit.bitstr)
		exit(0);
}

unsigned char	bin_to_c(char	binstr[8])
{
	unsigned char	c;

	c = 0;
	while (*binstr)
	{
		if (*binstr == '1')
			c = (c << 1) | 1;
		else
			c <<= 1;
		binstr++;
	}
	return (c);
}

void	convert_char(int i, siginfo_t *info)
{
	if (!i)
		g_bit.bitstr[g_bit.bitcount - 1] = '0';
	else
		g_bit.bitstr[g_bit.bitcount - 1] = '1';
	if (g_bit.bitcount == 8)
	{
		(void)info;
		g_bit.c = bin_to_c(g_bit.bitstr);
		write(1, &g_bit.c, 1);
		free(g_bit.bitstr);
		set_global();
	}
}
