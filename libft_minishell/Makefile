

.PHONY: all clean fclean re

NAME = libft_minishell.a
FLAGS = -Wall -Wextra -Werror

SRCS =	\
		change_env_str.c	\
		check_env_name.c	\
		error.c				\
		get_bin_paths.c		\
		get_env_str.c		\
		get_full_path.c		\


HEAD = \
         errors.h \
         libft_minishell.h	\

OBJ_DIR := ./obj

OBJ	:= $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
CFLAGS	:= -Wall -Wextra -Werror

NAME = libft_minishell

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
