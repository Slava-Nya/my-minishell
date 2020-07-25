# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/21 22:10:19 by hlorrine          #+#    #+#              #
#    Updated: 2019/11/18 19:26:07 by hlorrine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
HDR_PATH= includes/

SRC =  \
		ft_putnbr_fd.c	\
		ft_putendl_fd.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c	\
		ft_putnbr.c	\
		ft_putendl.c	\
		ft_putstr.c		\
		ft_putchar.c	\
		ft_itoa.c		\
		ft_strsplit.c	\
		ft_strtrim.c	\
		ft_strjoin.c	\
		ft_strsub.c		\
		ft_strnequ.c	\
		ft_strequ.c		\
		ft_strmapi.c	\
		ft_strmap.c		\
		ft_striteri.c	\
		ft_striter.c	\
		ft_strclr.c		\
		ft_strdel.c		\
		ft_strnew.c		\
		ft_memdel.c		\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_isprint.c	\
		ft_isascii.c	\
		ft_isalnum.c	\
		ft_isdigit.c	\
		ft_isalpha.c	\
		ft_atoi.c		\
		ft_strncmp.c	\
		ft_strcmp.c		\
		ft_strnstr.c	\
		ft_strstr.c		\
		ft_strrchr.c	\
		ft_memset.c		\
		ft_memalloc.c	\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memccpy.c	\
		ft_memmove.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_strdup.c		\
		ft_strcpy.c		\
		ft_strncpy.c	\
		ft_strcat.c		\
		ft_strncat.c	\
		ft_strlcat.c	\
		ft_strchr.c		\
		ft_lstnew.c		\
		ft_lsdelone.c	\
		ft_lstdel.c		\
		ft_lstadd.c		\
		ft_lstiter.c	\
		ft_lstmap.c		\
		ft_freesher.c	\
		ft_wordcount.c	\
		ft_reverselst.c	\
		ft_realloc.c	\
		ft_countalpha.c	\
		get_next_line.c	\
		ft_xmalloc.c	\
		ft_strcharsetsplit.c	\
		ft_arraylen.c	\
		ft_2darraycpy.c	\
		ft_nstrjoin.c

HEAD = libft.h \

OBJ_DIR := ./obj

OBJ	:= $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

LFLAGS	:= -L $(LIB_DIR) -lft

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(CMP_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEAD)
	gcc $(CFLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ) | lib
	gcc -o $(NAME) $(OBJ) $(LFLAGS)

lib:
	make -C $(LIB_DIR)

clean:
	rm -rf $(OBJ_DIR) $(CMP_DIR)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all
