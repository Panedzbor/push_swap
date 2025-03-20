# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 16:13:54 by earutiun          #+#    #+#              #
#    Updated: 2024/11/20 18:23:15 by earutiun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #///////////////////////

# target
NAME = push_swap

# complier and flags
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I. -Ilibft/
LFLAGS = -Llibft
LLIBS = -lft

# files
SOURCES = push_swap.c push.c swap.c rotate.c sort.c checks.c utils.c testing.c
OBJECTS = $(SOURCES:.c=.o)

# rules
all: $(NAME)

libft:
	$(MAKE) -C ./libft

$(NAME): libft $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LFLAGS) $(LLIBS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

test:
	ARG="`cat ../numbers.txt`"; valgrind ./push_swap $$ARG
	ARG="`cat ../numbers.txt`"; ./push_swap $$ARG | ../checker_linux $$ARG
	ARG="`cat ../numbers.txt`"; ./push_swap $$ARG | wc -l
	cat ../result.txt
	@echo "\n"

.PHONY: all clean fclean re libft test


