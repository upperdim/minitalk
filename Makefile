# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 12:26:25 by tunsal            #+#    #+#              #
#    Updated: 2023/11/15 08:34:00 by tunsal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLSRC				= client.c
CLOBJ				= $(CLSRC:.c=.o)
CLNAME				= client

SVSRC				= server.c
SVOBJ				= $(SVSRC:.c=.o)
SVNAME				= server

CC					= gcc
CFLAGS				= -Wall -Wextra -Werror

all:				./libft/libft.a $(CLNAME) $(SVNAME)

$(CLNAME):			$(CLSRC)
					$(CC) $(CFLAGS) $(CLSRC) -L libft -lft -o $(CLNAME)

$(SVNAME):			$(SVSRC)
					$(CC) $(CFLAGS) $(SVSRC) -L libft -lft -o $(SVNAME)

./libft/libft.a:
					make -C ./libft all

clean:
					make -C ./libft clean
					rm -f $(CLOBJ) $(SVOBJ)

fclean:				clean
					make -C ./libft fclean
					rm -f $(CLNAME) $(SVNAME)

re: 				fclean all