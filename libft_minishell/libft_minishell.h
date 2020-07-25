//
// Created by slavanya on 10.05.2020.
//

#ifndef LIBFT_MINISHELL_H
#define LIBFT_MINISHELL_H

# define MAX_PATH 256

#include <libft.h>

char	**get_bin_paths(char **env);
char	*get_env_str(char *env_name, char **env);
int		change_env_str(char *env_name, char *new_str, char ***env);
void 	get_full_path(char *full_path, char *start, char *end);
int		check_env_name(char  *argv);


#endif //LIBFT_MINISHELL_H
