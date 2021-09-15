#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef	struct	s_bit
{
	int	bitcount;
	char	c;
	char	*bitstr;
}		t_bit;

unsigned int	ft_len(char *s);
int		ft_wrs(char *s);
int		ft_wrsln(char *s);
char		*ft_ltoa(long i, int base);
long		ft_atol(char *s);
void		ft_handler(int signo, siginfo_t *info, void *ctx);
void		ft_sendmsg(char *s, pid_t pid);
void		ft_sendchar(unsigned char s, pid_t pid);
void		set_global();
void		convert_char(int i, siginfo_t *info);
unsigned char		bin_to_c(char binstr[8]);

#endif
