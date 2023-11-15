/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:32:22 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/15 09:55:01 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < BITS_PER_CHAR)
	{
		if ((c >> bit) & 1)
			kill(pid, BIT_1_SIGNAL);
		else
			kill(pid, BIT_0_SIGNAL);
		++bit;
		usleep(300);
	}
}

/* Send each char of `str` bit by bit including the null-terminator. */
void	send_msg(int pid, char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char(pid, str[i]);
		++i;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Error! Usage: <program name> <PID> <message>\n", 1);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || pid > 99999)
	{
		ft_putstr_fd("Error! PID is out of valid range.\n", 1);
		return (0);
	}
	send_msg(pid, argv[2]);
	return (0);
}
