# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 16:42:58 by dcastagn          #+#    #+#              #
#    Updated: 2023/03/13 10:04:09 by dcastagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = ./libft

PRINTF = ./printf

LIBFT_LIB = libft.a

PRINTF_LIB = libftprintf.a

SRCS = main.c	\
		map_reader.c \
		errors.c   \
		get_next_line.c \
		get_next_line_utils.c \
		checkmap.c	\
		checkmap2.c \
		draw_map.c	\
		move_player.c \
		functions_player.c \
		draw_exit.c    \

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
CC		= gcc
DEBUG	= gcc -g
LEAKS   = gcc -g -fsanitize=address
FLAGS	= -Wall -Wextra -Werror
INCS	= ./

all: $(NAME)
#MACOS INCLUDES
MLXFLAGS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@


$(NAME): $(OBJS)
	make re -C $(PRINTF)
	make re -C $(LIBFT)
	$(CC) $(MLXFLAGS) $(LIBFT)/$(LIBFT_LIB)  $(PRINTF)/$(PRINTF_LIB) $(OBJS) -o $(NAME)

game:
	leaks -atExit -- ./so_long maps/map1.ber

linux: $(OBJS)
	make re -C $(PRINTF)
	make re -C $(LIBFT)
	$(CC) $(OBJS) $(LIBFT)/$(LIBFT_LIB)  $(PRINTF)/$(PRINTF_LIB) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lXrender -lm -lz -o $(NAME)

fclean: clean
	$(RM) $(NAME) $(LIBFT)/$(LIBFT_LIB)  $(PRINTF)/$(PRINTF_LIB)

clean:
	$(RM) $(OBJS)
	make clean -C $(PRINTF)
	make clean -C $(LIBFT)

re: fclean all

.PHONY: all linux macos clean fclean re .c.o