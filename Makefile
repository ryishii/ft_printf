# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryishii <ryishii@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 00:05:09 by ryishii           #+#    #+#              #
#    Updated: 2021/03/25 01:28:15 by ryishii          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = ./
SRC = ft_printf.c ft_printf_utils.c ft_printf_utils2.c \
		ft_put_cs.c ft_put_px.c ft_put_di.c ft_put_u.c read_args.c
SRCS = ${addprefix ${SRCDIR}, ${SRC}}
OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS) libft/*.o

fclean:
	rm -rf $(OBJS) $(NAME) libft/libft.a libft/*.o

re: fclean all

.PHONY:
	all clean fclean re