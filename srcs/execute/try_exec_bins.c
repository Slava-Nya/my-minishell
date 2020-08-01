//
// Created by slavanya on 01.05.2020.
//

#include "libft.h"
#include "libft_minishell.h"

char		*try_exec_bins(char **read_argv, char **env_paths, char *full_env_path)
{
	int 	i;

	i = 0;
	while (env_paths[i])
	{
		get_full_path(full_env_path, env_paths[i], read_argv[0]);
		if (!(access(full_env_path, F_OK | X_OK)))
			return (full_env_path);
		i++;
	}
	return (NULL);
}
