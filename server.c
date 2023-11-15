/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:32:20 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/15 11:12:42 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_bit(int sig, siginfo_t *info, void *context)
{
	unsigned char	received_bit;

	(void) context;
	if (sig == BIT_1_SIGNAL)
		received_bit = 0x01;
	else
		received_bit = 0x00;
	g_curr_char.c += (received_bit & 1) << g_curr_char.bit_index;
	g_curr_char.bit_index++;
	if (g_curr_char.bit_index == BITS_PER_CHAR)
	{
		if (g_curr_char.c == '\0')
		{
			ft_putchar_fd('\n', 1);
			kill(info->si_pid, SV_MESSAGE_RECEIVED_SIGNAL);
		}
		else
			ft_putchar_fd(g_curr_char.c, 1);
		g_curr_char.c = 0;
		g_curr_char.bit_index = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sigact;

	(void) argv;
	if (argc != 1)
	{
		ft_putstr_fd("Error! Program received arguments.\n", 1);
		return (1);
	}
	ft_printf("Server PID: %d\n", getpid());
	sigact.sa_sigaction = receive_bit;
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = 0;
	while (1)
	{
		sigaction(BIT_0_SIGNAL, &sigact, NULL);
		sigaction(BIT_1_SIGNAL, &sigact, NULL);
		pause();
	}
	return (0);
}
