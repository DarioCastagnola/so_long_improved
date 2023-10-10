# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 10:29:05 by dcastagn          #+#    #+#              #
#    Updated: 2023/02/06 17:03:19 by dcastagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS =  ft_putchar.c	 \
	    ft_putnbr.c 	 \
		ft_printf.c		 \
		ft_putsrc.c		 \
		ft_putstr.c		 \
		ft_putbignbr.c	 \
		ft_putaddress.c  \
		ft_hexbig.c		 \
		ft_hexsmall.c    \
		ft_hexsmall_p.c  \

FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJS = $(SRCS:.c=.o)
.o:.c
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}
$(NAME): ${OBJS}
	ar rcs $(NAME) $(OBJS)
all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
