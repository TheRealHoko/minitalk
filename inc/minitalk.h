#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

unsigned int	ft_len(char *s);
int		ft_wrs(char *s);
int		ft_wrsln(char *s);
char		*ft_ltoa(long i, int base);
long		ft_atol(char *s);
void		ft_handler(int signo);
void		ft_sendmsg(char *s, pid_t pid);
void		ft_sendchar(unsigned char s, pid_t pid);
void	bitin(int bit);

#endif
