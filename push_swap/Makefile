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
# **************************************************************************** #

# target
NAME = push_swap

# complier and flags
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I. -Ilibft/
LFLAGS = -Llibft
LLIBS = -lft

# files
SRC1 = push_swap.c push.c swap.c rotate.c sort.c minsort.c sortthree.c checks.c check_if_sorted.c utils.c
SRC2 = push_swap.c push.c swap.c rotate.c sort.c minsort.c sortthree.c checks.c check_if_sorted.c utils.c ../testing.c
SOURCES = $(SRC1)
OBJECTS = $(SOURCES:.c=.o)

# rules
all: SOURCES = $(SRC1)
all: OBJECTS = $(SOURCES:.c=.o)
all: $(NAME)

ad: SOURCES = $(SRC2)
ad: OBJECTS = $(SOURCES:.c=.o)
ad: ../testing.o
ad: CFLAGS += -D TESTING_ENABLED
ad: $(NAME)

libft:
	$(MAKE) -C ./libft

$(NAME): libft $(SOURCES:.c=.o)
	$(CC) $(CFLAGS) $(SOURCES:.c=.o) $(LFLAGS) $(LLIBS) -o $(NAME)

../testing.o: ../testing.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJECTS)
	rm -f ../testing.o

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

ret: fclean ad

test:
	ARG="`cat ../numbers.txt`"; valgrind ./push_swap $$ARG
	ARG="`cat ../numbers.txt`"; ./push_swap $$ARG | ../checker_linux $$ARG
	ARG="`cat ../numbers.txt`"; ./push_swap $$ARG | wc -l
	cat ../result.txt
	@echo "\n"
	norminette -R CheckForbiddenSourceHeader

t:
	@printf "./push_swap %s\n" "$$(cat ../numbers.txt)"
	ARG="`cat ../numbers.txt`"; ./push_swap $$ARG | ../checker_linux $$ARG
	ARG="`cat ../numbers.txt`"; ./push_swap $$ARG | wc -l
	cat ../result.txt
	@echo "\n"

.PHONY: all clean fclean re libft test ad t ret


