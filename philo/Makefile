# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile 	                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmande <anmande@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 09:39:23 by anmande           #+#    #+#              #
#    Updated: 2023/02/06 10:28:28 by anmande          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS_DIR = srcs

SRCS =	$(SRCS_DIR)/main.c \
		$(SRCS_DIR)/parseur.c \
		$(SRCS_DIR)/tools.c \
		$(SRCS_DIR)/philo.c \
		$(SRCS_DIR)/routine.c \
		$(SRCS_DIR)/init.c \

OBJS_DIR = objs
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all