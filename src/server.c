#include "minitalk.h"

int	main()
{
	pid_t			pid1;
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &ft_handler;
	pid1 = getpid();
	set_global();
	ft_wrs("Server PID = ");
	ft_wrsln(ft_ltoa(pid1, 10));
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (42);
	return (0);
}
