/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:16:55 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:16:59 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "errors.h"
#include "libft_minishell.h"

static void		free_env(char ***env)
{
	int i;

	i = 0;
	while ((*env)[i])
	{
		free((*env)[i]);
		i++;
	}
	free(*env);
}

static char		**cpy_env(char ***arr, int dest_len, int del_str)
{
	char	**dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!arr || !(*arr))
		return (NULL);
	dest = ft_xmalloc(sizeof(char *) * (dest_len + 1));
	dest[dest_len] = NULL;
	while (i < dest_len)
	{
		if (j == del_str)
			j++;
		dest[i] = ft_strdup((*arr)[j]);
		i++;
		j++;
	}
	return (dest);
}

static void		unsetenv_argv(char *argv, char ***env)
{
	int		cnt;
	char	*argv_full;
	char	**new_env;

	argv_full = ft_strjoin(argv, "=");
	cnt = change_env_str(argv_full, "", env);
	if (cnt >= 0)
	{
		new_env = cpy_env(env, ft_arraylen(*env) - 1, cnt);
		free_env(env);
		(*env) = new_env;
	}
	free(argv_full);
}

static int		check_argv(char *argv)
{
	int i;

	if ((!ft_isalpha(argv[0])) && argv[0] != '_')
		return (0);
	i = 1;
	while (argv[i])
	{
		if ((!ft_isalpha(argv[i])) && (!ft_isdigit(argv[i]))
			&& argv[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int				unsetenv_main(char **argv, char ***env)
{
	int argc;
	int cnt;

	argc = ft_arraylen(argv);
	if (argc == 1)
		return (0);
	cnt = 1;
	while (cnt < argc)
	{
		if (check_argv(argv[cnt]))
			unsetenv_argv(argv[cnt], env);
		else
			puterror(env_invalid_id, argv[cnt], "unsetenv");
		cnt++;
	}
	return (0);
}
