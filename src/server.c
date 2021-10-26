/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:35:17 by jzeybel           #+#    #+#             */
/*   Updated: 2021/10/26 18:35:19 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	pid_t				pids;
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO | SA_RESTART;
	act.sa_sigaction = &ft_handler;
	pids = getpid();
	ft_wrs("Server PID = ");
	ft_wrsln(ft_ltoa(pids, 10));
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (42)
		;
	return (0);
}
