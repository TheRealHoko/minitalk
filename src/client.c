#include "minitalk.h"
#include <stdio.h>

void	ft_ack(int signo)
{
	if (signo == SIGUSR1)
		ft_wrsln("ack");
}

int	main(int ac, char **av)
{
	pid_t	pidc;
	pid_t	pids;
	struct sigaction act;

	pidc = getpid();
	pids = ft_atol(av[1]);
	act.sa_flags = SA_RESTART;
	act.sa_handler = &ft_ack;
	if ((ac == 3) && (pids > 0))
	{
		// PID
		ft_wrs("Client PID = ");
		ft_wrsln(ft_ltoa(pidc, 10));
		ft_wrs("Server PID = ");
		ft_wrsln(av[1]);

		// Message
		ft_wrs("msg  = ");
		ft_wrsln(av[2]);
		ft_sendmsg(av[2], pids);
		sigaction(SIGUSR1, &act, 0);
	}
	else
		ft_wrs("./client <PID> <msg>\n");
	return (0);
}
