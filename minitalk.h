#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

# define BITS_PER_CHAR 7

typedef struct incoming_char
{
	char c;
	int bit_index;
} incoming_char_t;

incoming_char_t g_curr_char;

#endif
