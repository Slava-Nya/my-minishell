.PHONY: all clean fclean re

NAME		= minishell
FLAGS		= -Wall -Wextra -Werror

SRC_DIR		= ./srcs
BUILD_DIR	= ./obj
INC_DIR		= ./includes

FT_DIR		= ./libft
INC_FT		= ./libft
LIB_FT		= -L$(FT_DIR) -lft

FT_MIN_DIR	= ./libft_minishell
INC_FT_MIN	= ./libft_minishell/include
LIB_FT_MIN	= -L$(FT_MIN_DIR) -lft_minishell

SRCS		=	\
			main.c					\
			builtins/cd_main.c		\
			builtins/echo_main.c	\
			builtins/env_main.c	\
			builtins/exec_builtins.c\
			builtins/exit_main.c	\
			builtins/setenv_main.c	\
			builtins/unsetenv_main.c		\
			execute/get_execute.c	\
			execute/try_exec_bins.c	\
			parse/get_parse.c		\
			parse/dollar_esc/dollar_esc.c	\
			parse/dollar_esc/dollar_get_begin.c		\
			parse/dollar_esc/dollar_get_end.c		\
			parse/dollar_esc/dollar_get_middle.c	\
			parse/tilda_esc/tilda_esc.c

INCS		= -I$(INC_DIR) -I$(INC_FT) -I$(INC_FT_MIN)

OBJ			= $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))

CFLAGS		= -Wall -Wextra -Werror


all: $(BUILD_DIR) $(LIB_FT) $(LIB_FT_MIN) $(NAME)

$(LIB_FT):
	make -C $(FT_DIR)

$(LIB_FT_MIN):
	make -C $(FT_MIN_DIR)

$(NAME): $(BUILD_DIR) $(OBJ)
	gcc $(FLAGS) $(LIB_FT) $(LIB_FT_MIN) $(OBJ) $(INCS) -o $(NAME) 

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/builtins
	mkdir -p $(BUILD_DIR)/execute
	mkdir -p $(BUILD_DIR)/parse
	mkdir -p $(BUILD_DIR)/parse/dollar_esc
	mkdir -p $(BUILD_DIR)/parse/tilda_esc

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	gcc $(CFLAGS) $(INCS) -o $@ -c $<

clean:
	rm -rf $(BUILD_DIR)
	make clean -C $(FT_DIR)
	make clean -C $(FT_MIN_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
