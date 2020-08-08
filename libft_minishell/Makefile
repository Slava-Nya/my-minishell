# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/08 16:35:23 by hlorrine          #+#    #+#              #
#    Updated: 2020/08/08 16:35:28 by hlorrine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME		= libft_minishell.a
FLAGS		= -Wall -Wextra -Werror

SRC_DIR		= ./src
BUILD_DIR	= ./obj
INCLUDE_DIR	= ./include

FT_DIR		=	../libft
FT_INC_DIR	=	../libft

SRC			=	\
				change_env_str.c	\
				check_env_name.c	\
				error.c				\
				get_bin_paths.c		\
				get_env_str.c		\
				get_full_path.c

OBJ			=	$(addprefix $(BUILD_DIR)/,$(SRC:.c=.o))

INCS		=	-I$(INCLUDE_DIR) -I$(FT_INC_DIR)
LIBS		=	-L$(FT_DIR) -lft

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	gcc $(FLAGS) $(INCS) -o $@ -c $<

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
