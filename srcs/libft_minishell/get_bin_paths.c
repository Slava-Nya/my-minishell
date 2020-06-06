//
// Created by slavanya on 26.04.2020.
//

#include "libft_minishell.h"

char	**get_bin_paths(char **env)
{
	char 	*bins_full_path;
	char 	**bins_paths;

	bins_full_path = get_env_str("PATH", env);
	bins_paths = ft_strsplit(bins_full_path, ':');
	int i = -1;
	return(bins_paths);
}