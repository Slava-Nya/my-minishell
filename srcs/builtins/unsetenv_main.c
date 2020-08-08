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

static void		unsetenv_argv(char *argv, char ***env)
{
	int 	cnt;
	char	*argv_full;

	argv_full = ft_strjoin(argv, "=");
	cnt = change_env_str(argv_full, "", env);
	if (cnt >= 0)
		(*env)[cnt][0] = '\0';
	free(argv_full);
}

static int 	check_argv(char  *argv)
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

int 	unsetenv_main(char **argv, char ***env)
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
