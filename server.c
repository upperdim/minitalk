/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:32:20 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/15 09:54:08 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_msg(int received_bit)
{
	g_curr_char.c += (received_bit & 1) << g_curr_char.bit_index;
	g_curr_char.bit_index++;
	if (g_curr_char.bit_index == BITS_PER_CHAR)
	{
		if (g_curr_char.c == 0)
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(g_curr_char.c, 1);
		g_curr_char.c = 0;
		g_curr_char.bit_index = 0;
	}
}

int	main()
{
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		signal(BIT_0_SIGNAL, receive_msg);
		signal(BIT_1_SIGNAL, receive_msg);
		pause();
	}
	return (0);
}
