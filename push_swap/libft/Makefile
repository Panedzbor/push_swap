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
NAME = libft.a

# complier and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ift_printf/

# files
SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
          ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back_bonus.c \
          ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
          ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
          ft_lstsize_bonus.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
          ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
          ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
          ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
          ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
          ft_toupper.c
PRINTF_SOURCES = ft_printf/allign.c ft_printf/check_format_str.c ft_printf/compare_chars.c \
				ft_printf/extract_format_val.c ft_printf/format.c ft_printf/format_num.c \
                ft_printf/format_str.c ft_printf/ft_printf.c ft_printf/ft_ptoa.c \
                ft_printf/ft_utoa.c ft_printf/ft_xtoa.c ft_printf/inv_helper_funcs.c \
                ft_printf/inv_write_spec.c ft_printf/inv_write_str.c \
                ft_printf/printing_utils.c ft_printf/printing_utils2.c \
                ft_printf/sum_chars.c ft_printf/utils.c ft_printf/utils2.c \
                ft_printf/validate_nums.c
ALL_SOURCES = $(SOURCES) $(PRINTF_SOURCES)
OBJECTS = $(ALL_SOURCES:%.c=%.o)

# rules
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


