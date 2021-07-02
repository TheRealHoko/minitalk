#include "minitalk.h"

static	t_bit	g_bit;

unsigned int	ft_len(char *s)
{
	unsigned int	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

int	ft_wrs(char	*s)
{
	return (write(1, s, ft_len(s)));
}

int	ft_wrsln(char	*s)
{
	int	i;

	i = write(1, s, ft_len(s));
	write(1, "\n", 1);
	return (i);
}

int	ft_sum(long i, int base)
{
	int	j;

	j = 0;
	while (i)
	{
		i /= base;
		j++;
	}
	return (j);
}

char	*ft_ltoa(long i, int base)
{
	static char	s[10];
	int	size;
	int	len;

	size = ft_sum(i, base);
	if (base == 2)
	{
		len = size;
		if (len < 8)
		{
			len = 8 - len;
			size += len;
			while (len--)
				s[len] = '0';
		}
	}
	s[size] = 0;
	while (size--)
	{
		s[size] = (i % base) + 48;
		i /= base;
	}
	return (s);
}

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

void	ft_sendmsg(char s, pid_t pid)
{
	char	*s1;
	char	c;

	s1 = ft_ltoa(s, 2);
	c = bin_to_c(s1);
	ft_wrs(s1);
	ft_wrs(" ");
	write(1, &c, 1);
	ft_wrs("\n");
	while (*s1)
	{
		if (*s1 == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		s1++;
	}
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

char	bin_to_c(char	binstr[8])
{
	char	c;

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
		if ((g_bit.c >= 32) && (g_bit.c <= 126))
			write(1, &g_bit.c, 1);
		free(g_bit.bitstr);
		set_global();
	}
}
