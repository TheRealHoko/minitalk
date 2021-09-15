#include "minitalk.h"
#include <stdio.h>

void	ft_ack(int signo)
{
	if (signo == SIGUSR1)
	{
		printf("hi\n");
	}
}

int	main(int ac, char **av)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = getpid();
	pid2 = ft_atol(av[1]);
	if ((ac == 3) && (pid2 > 0))
	{
		// PID
		ft_wrs("Client PID = ");
		ft_wrsln(ft_ltoa(pid1, 10));
		ft_wrs("Server PID = ");
		ft_wrsln(av[1]);

		// Message
		ft_wrs("msg  = ");
		ft_wrsln(av[2]);
		ft_sendmsg(av[2], pid2);
	}
	else if (ac == 2)
		return (ft_wrsln(ft_ltoa(ft_atol(av[1]), 2)));
	else
		ft_wrs("./client <PID> <msg>\n");
	return (0);
}
