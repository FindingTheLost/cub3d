# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 19:18:32 by pde-alme          #+#    #+#              #
#    Updated: 2026/05/11 15:47:34 by pde-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

BSDLIB	= -lbsd

MATHLIB	= -lm

HDR		= libft.h

SRC		= ft_atoi.c				\
		  ft_atol.c				\
		  ft_bzero.c			\
		  ft_calloc.c			\
		  ft_eof.c				\
		  ft_fbool.c			\
		  ft_gnl.c				\
		  ft_gnl_utils.c		\
		  ft_isalnum.c			\
		  ft_isalpha.c			\
		  ft_isascii.c			\
		  ft_isdigit.c			\
		  ft_isprint.c			\
		  ft_itoa.c				\
		  ft_lstadd_back.c		\
		  ft_lstadd_front.c		\
		  ft_lstclear.c			\
		  ft_lstdelone.c		\
		  ft_lstiter.c			\
		  ft_lstlast.c			\
		  ft_lstmap.c			\
		  ft_lstnew.c			\
		  ft_lstsize.c			\
		  ft_memchr.c			\
		  ft_memcmp.c			\
		  ft_memcpy.c			\
		  ft_memmove.c			\
		  ft_memset.c			\
		  ft_printf.c			\
		  ft_printf_utils1.c	\
		  ft_printf_utils2.c	\
		  ft_putchar_fd.c		\
		  ft_putendl_fd.c		\
		  ft_putnbr_fd.c		\
		  ft_putstr_fd.c		\
		  ft_split.c			\
		  ft_strchr.c			\
		  ft_strcmp.c			\
		  ft_strdup.c			\
		  ft_striteri.c			\
		  ft_strjoin.c			\
		  ft_strlcat.c			\
		  ft_strlcpy.c			\
		  ft_strlen.c			\
		  ft_strmapi.c			\
		  ft_strbcmp.c			\
		  ft_strncmp.c			\
		  ft_strnstr.c			\
		  ft_strrchr.c			\
		  ft_strtrim.c			\
		  ft_substr.c			\
		  ft_tolower.c			\
		  ft_toupper.c

OBJ		= $(SRC:.c=.o)

AR		= rc



all: $(HDR) $(NAME)

$(NAME): $(OBJ)
	@ar $(AR) $(NAME) $(OBJ)
	@printf "\033[34;7m=======================| LIBFT SUCCESSFULY ARCHIVED |=======================\033[0m\n"

clean:
	@rm -f $(OBJ)
	@printf "\033[33;7m====================| OBJECT FILES SUCCESSFULY REMOVED |====================\033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[31;7m=======================| ARCHIVE SUCCESSFULY REMOVED |======================\033[0m\n"

re: fclean all



.PHONY: all clean fclean re
