/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:32:22 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/13 10:36:30 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 7)
	{
		if ((c >> bit) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		++bit;
		usleep(300);
	}
}

/* Send each 7-byte char of `str` bit by bit including the null-terminator. */
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
	unsigned char		unicode_ch[4];
	int					pid;

	if (argc != 3)
	{
		ft_printf("Error! Usage: <program name> <PID> <message>\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || pid > 99999)
	{
		ft_printf("Error! PID is out of valid range.\n");
		return (0);
	}
	send_msg(pid, argv[2]);
	return (0);
}
