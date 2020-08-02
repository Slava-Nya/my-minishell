//
// Created by slavanya on 26.04.2020.
//

#include "minishell.h"
#include "builtins.h"
#include "libft_minishell.h"
#include "errors.h"

static void 	exec_bins(char **read_argv, char ***env)
{
	char 	**env_paths;
	char 	full_env_path[MAX_PATH];
	int 	i;

	i = 0;
	if (!(env_paths = get_bin_paths(*env)))
	{
		puterror(false_command, read_argv[0], "");
		return ;
	}
	if (try_exec_bins(read_argv, env_paths, full_env_path))
	{
		if (!fork())
		{
			execve(full_env_path, read_argv, *env);
			exit(0);
		}
		else
			wait(NULL);
	}
	else
		puterror(false_command, read_argv[0], "");
	while (env_paths[i])
	{
		free(env_paths[i]);
		i++;
	}
	free(env_paths);
}

void 	get_execute(char **read_argv, char ***env)
{
	if (exec_builtins(read_argv, env))
		return ;
	else
		exec_bins(read_argv, env);
}