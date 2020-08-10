/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:16:09 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:16:11 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"
#include "libft_minishell.h"
#include "errors.h"

static int		is_path(const char *path)
{
	if (*path == '/' || (*path == '.' && *(path + 1) == '/') \
		|| (*path == '.' && *(path + 1) == '.' && *(path + 2) == '/'))
		return (1);
	return (0);
}

static void		free_env_paths(char **env_paths)
{
	int	i;

	i = 0;
	while (env_paths[i])
	{
		free(env_paths[i]);
		i++;
	}
	free(env_paths);
}

static void		exec_bins(char **read_argv, char ***env)
{
	char	**env_paths;
	char	full_env_path[MAX_PATH];

	env_paths = get_bin_paths(*env);
	if (env_paths == NULL && !(is_path(read_argv[0])))
	{
		puterror(false_command, read_argv[0], "");
		return ;
	}
	if (try_exec_bins(read_argv, env_paths, full_env_path))
	{
		if (!fork())
			exit((execve(full_env_path, read_argv, *env)));
		else
			wait(NULL);
	}
	if (env_paths)
		free_env_paths(env_paths);
}

void			get_execute(char **read_argv, char ***env)
{
	if (exec_builtins(read_argv, env))
		return ;
	else
		exec_bins(read_argv, env);
}
