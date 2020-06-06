//
// Created by slavanya on 26.04.2020.
//

#include <minishell.h>
#include <wait.h>
#include "builtins.h"
#include "../libft_minishell/libft_minishell.h"
#include "../libft_minishell/errors.h"

void 	get_execute(char **read_argv, char ***env)
{
	char 	**env_paths;
	char 	full_env_path[MAX_PATH];

	if ((exec_builtins(read_argv, env)))
		return ;
	env_paths = get_bin_paths(*env);
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
}