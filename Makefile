


SRCS :=	main.c					\
		builtins/cd_main,c		\
		builtins/echo_main.c	\
		builtins/env_maimn.c	\
		builtins/exec_builtins.c\
		builtins/exit_main.c	\
		builtins/setenv_main.c	\
		builtins/unsetenv.c		\
		execute/get_execute.c	\
		execute/try_exec_bins.c	\
		parse/get_parse.c		\
		parse/dollar_esc/dollar_esc.c	\
		parse/dollar_esc/dollar_get_begin.c		\
		parse/dollar_esc/dollar_get_end.c		\
		parse/dollar_esc/dollar_get_middle.c	\
		tilda_esc/tilda_esc.c					\

SRC_DIR := ./src

LIB_DIR := ./libft ./libft_minishell.c

INC := -I includes/ -I libft/ -I libft_minishell/

HEAD = \
          includes/builtins.h \
          includes/minishell.h\

OBJ_DIR := ./obj
CMP_DIR	:= $(OBJ_DIR)/builtins		\
			$(OBJ_DIR)/execute		\
			$(OBJ_DIR)/srcs			\
			$(OBJ_DIR)/parse		\

OBJ	:= $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

CFLAGS	:= -Wall -Wextra -Werror

LFLAGS	:= -L $(LIB_DIR) -lft

NAME = ft_minishell

.PHONY: all clean lib fclean re

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
