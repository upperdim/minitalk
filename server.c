/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:32:20 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/13 10:30:24 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	receive_msg(int signum, siginfo_t *info, void *context)
{
	int	i;

	i = 0;
	
}

int	main()
{
	struct sigaction	sigact;

	ft_print("Server PID: %d\n", getpid());
	sigact.sa_sigaction = receive_msg;
	sigact.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &receive_msg, NULL);
		sigaction(SIGUSR2, &receive_msg, NULL);
		pause();
	}
	return (0);
}
