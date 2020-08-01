//
// Created by slavanya on 23.04.2020.
//

#ifndef MINISHELL_H
#define MINISHELL_H

#include <libft.h>

# define BUF 1024
# define MAX_PATH 256

int		main(int argc, char  **argv, char **env);
char **get_parse(char **argv, char *read_buf, char **env);

void 	get_execute(char **read_argv, char ***env);
char	*try_exec_bins(char **read_argv, char **env_paths, char *full_env_path);

void	tilda_esc(char **read_argv, char *home, int tilda_i);

void dollar_esc(char **read_argv, char **argv, char **env);
void 	dollar_get_begin(char **read_argv, char **begin, int dollar_i);
char	*dollar_get_middle(char **read_argv, char **argv, char **env, int end_of_middle);
int 	dollar_get_end(char **read_argv, char **end, int dollar_i);

#endif //MINISHELL_H

