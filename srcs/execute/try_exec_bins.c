/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_exec_bins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:16:14 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:16:17 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_minishell.h"
#include <sys/stat.h>
#include <errors.h>

static int		is_path(const char *path)
{
	if (*path == '/' || (*path == '.' && *(path + 1) == '/') \
		|| (*path == '.' && *(path + 1) == '.' && *(path + 2) == '/'))
		return (1);
	return (0);
}

static char		*check_path(char *path, char *full_env_path)
{
	int				i;
	struct stat		info;
	unsigned int	type;

	i = 0;
	stat(path, &info);
	type = info.st_mode & S_IFMT;
	if (type == S_IFDIR)
	{
		return (NULL);
	}
	ft_bzero(full_env_path, MAX_PATH);
	while (path[i])
	{
		full_env_path[i] = path[i];
		i++;
	}
	return (full_env_path);
}

char			*try_exec_bins(char **read_argv, char **env_paths,\
char *full_env_path)
{
	int i;

	i = 0;
	if (is_path(read_argv[0]))
	{
		if (!(full_env_path = check_path(read_argv[0], full_env_path)))
		{
			puterror(no_rules, read_argv[0], "");
			return (NULL);
		}
		if (!(access(full_env_path, F_OK | X_OK)))
			return (full_env_path);
	}
	while (env_paths[i])
	{
		get_full_path(full_env_path, env_paths[i], read_argv[0]);
		if (!(access(full_env_path, F_OK | X_OK)))
			return (full_env_path);
		i++;
	}
	puterror(false_command, read_argv[0], "");
	return (NULL);
}
