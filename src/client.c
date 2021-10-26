/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:35:10 by jzeybel           #+#    #+#             */
/*   Updated: 2021/10/26 18:35:12 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	ft_ack(int signo)
{
	if (signo == SIGUSR1)
		ft_wrsln("SIGUSR1\n");
	else if (signo == SIGUSR2)
		ft_wrsln("SIGUSR2\n");
}

int	main(int ac, char **av)
{
	pid_t				pidc;
	pid_t				pids;
	struct sigaction	act;

	pidc = getpid();
	pids = ft_atol(av[1]);
	act.sa_flags = SA_RESTART;
	act.sa_handler = &ft_ack;
	if ((ac == 3) && (pids > 0))
	{
		sigaction(SIGUSR1, &act, 0);
		sigaction(SIGUSR2, &act, 0);
		ft_wrs("Client PID = ");
		ft_wrsln(ft_ltoa(pidc, 10));
		ft_wrs("Server PID = ");
		ft_wrsln(av[1]);
		ft_wrs("msg  = ");
		ft_sendmsg(av[2], pids);
	}
	else
		ft_wrs("./client <PID> <msg>\n");
	return (0);
}
