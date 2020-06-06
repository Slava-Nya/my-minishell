//
// Created by slavanya on 23.04.2020.
//

#ifndef MINISHELL_H
#define MINISHELL_H

#include <libft.h>

# define BUF 1024
# define MAX_PATH 256

char	**get_parse(char **argv, int argc, char *read_buf, char **env);
void 	get_execute(char **read_argv, char ***env);
char	*try_exec_bins(char **read_argv, char **env_paths, char *full_env_path);

#endif //MINISHELL_H

