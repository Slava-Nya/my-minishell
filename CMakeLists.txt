cmake_minimum_required(VERSION 3.16)
project(minishell C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(libft)
include_directories(libft_minishell/include)

add_executable(minishell
        includes/minishell.h
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_countalpha.c
        libft/ft_freesher.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_lstadd.c
        libft/ft_lstdel.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_realloc.c
        libft/ft_reverselst.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtrim.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/ft_wordcount.c
        libft/get_next_line.c
        libft/libft.h
        srcs/main.c srcs/parse/get_parse.c srcs/execute/get_execute.c libft_minishell/src/get_bin_paths.c srcs/execute/try_exec_bins.c libft/ft_strcharsetsplit.c libft/ft_xmalloc.c srcs/builtins/echo_main.c srcs/builtins/exec_builtins.c srcs/builtins/cd_main.c srcs/builtins/unsetenv_main.c srcs/builtins/env_main.c srcs/builtins/setenv_main.c srcs/builtins/exit_main.c includes/builtins.h libft_minishell/src/get_env_str.c libft/ft_arraylen.c libft_minishell/src/error.c libft_minishell/src/change_env_str.c libft/ft_2darraycpy.c libft/ft_nstrjoin.c libft_minishell/src/get_full_path.c libft/ft_chrsetcmp.c libft/ft_piecestrcpy.c libft_minishell/src/check_env_name.c srcs/parse/tilda_esc/tilda_esc.c srcs/parse/dollar_esc/dollar_esc.c srcs/parse/dollar_esc/dollar_get_begin.c srcs/parse/dollar_esc/dollar_get_end.c srcs/parse/dollar_esc/dollar_get_middle.c)
