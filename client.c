/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:32:22 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/15 11:52:04 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_validation(int signal)
{
	if (signal == SV_MESSAGE_RECEIVED_SIGNAL)
		ft_putstr_fd("Server has received the message successfully.\n", 1);
}

void	send_char(int server_pid, char c)
{
	int	bit_index;

	bit_index = 0;
	while (bit_index < BITS_PER_CHAR)
	{
		if ((c >> bit_index) & 1)
			kill(server_pid, BIT_1_SIGNAL);
		else
			kill(server_pid, BIT_0_SIGNAL);
		++bit_index;
		usleep(300);
	}
}

/* Send each char of `str` bit by bit including the null-terminator. */
void	send_msg(int server_pid, char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char(server_pid, str[i]);
		++i;
	}
	send_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
	{
		ft_putstr_fd("Error! Usage: <program name> <PID> <message>\n", 1);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0 || server_pid > 99999)
	{
		ft_putstr_fd("Error! PID is out of valid range.\n", 1);
		return (2);
	}
	send_msg(server_pid, argv[2]);
	signal(SV_MESSAGE_RECEIVED_SIGNAL, send_validation);
	// send_char(server_pid, '\0');
	while (1)
		;
	return (0);
}
