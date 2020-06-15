//
// Created by slavanya on 23.04.2020.
//

#ifndef MINISHELL_H
#define MINISHELL_H

#include <libft.h>

# define BUF 1024
# define MAX_PATH 256

void 	get_execute(char **read_argv, char ***env);
char	*try_exec_bins(char **read_argv, char **env_paths, char *full_env_path);

char	**get_parse(char **argv, int argc, char *read_buf, char **env);
void	tilda_esc(char **read_argv, char *home, int tilda_i);
void	dollar_esc(char **read_argv, char **argv, int argc, char **env);

void 	get_begin(char **read_argv, char **begin, int dollar_i);
int 	get_end(char **read_argv, char **end, int dollar_i);
void 	get_middle(char **read_argv, char **argv, char **env, int end_of_middle)

#endif //MINISHELL_H

