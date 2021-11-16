# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 21:17:00 by dokkim            #+#    #+#              #
#    Updated: 2021/11/16 16:45:59 by dokkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
BONUS_NAME = philo_bonus
INC		= -I ./includes
LIBS	= -lpthread
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS = ./srcs/main.c \
		./srcs/init/init.c \
		./srcs/init/init_system.c \
		./srcs/utils/libft.c \
		./srcs/validate/validate.c \
		./srcs/execute/time.c \
		./srcs/execute/execute.c \
		./srcs/execute/philosophers.c

OBJS = $(SRCS:.c=.o)

%.o		:	%.c
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

all : $(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(INC) $(LIBS) -o $(NAME)

clean :
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME) $(BONUS_NAME)

bonus : all $(BONUS_NAME)

re : fclean all

.PHONY: all clean fclean re bonus
