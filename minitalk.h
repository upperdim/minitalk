/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:47:26 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/15 11:49:15 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

# define BITS_PER_CHAR 7

# define BIT_0_SIGNAL SIGUSR1
# define BIT_1_SIGNAL SIGUSR2
# define SV_MESSAGE_RECEIVED_SIGNAL SIGUSR2 

typedef struct incoming_char
{
	unsigned char	c;
	int				bit_index;
}	t_incoming_char;

t_incoming_char	g_curr_char;

#endif
