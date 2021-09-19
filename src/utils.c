#include "minitalk.h"

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
	return (i + 1);
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
