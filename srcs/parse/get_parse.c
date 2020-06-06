//
// Created by slavanya on 26.04.2020.
//

#include <minishell.h>
#include "../libft_minishell/libft_minishell.h"

static void 	to_argv_change(char **read_argv, char **argv, int argc, int dollar_i)
{
	char *start;
	char *end;
	int argv_i;

	start = ft_piecestrcpy(*read_argv, 0, dollar_i - 1);
	end = ft_piecestrcpy(*read_argv, dollar_i + 2, ft_strlen(*read_argv));
	argv_i = (*read_argv)[dollar_i + 1] - '0';
	if (argv_i <= argc)
		(*read_argv) = ft_nstrjoin(3, start, argv[argv_i], end);
	else
		(*read_argv) = ft_nstrjoin(2, start, end);
}

static void 	to_home_change(char **read_argv, char *home, int tilda_i)
{
	char *tmp;
	char *start;
	char *end;

	if (!(*read_argv)[1])
		*read_argv = home;
	else if (tilda_i == 0 && (*read_argv)[1] == '/')
	{
		if (!((*read_argv)[2]))
			(**read_argv) = '\0';
		else
			(*read_argv) += 2;
		tmp = ft_nstrjoin(3, home, "/", (*read_argv));
		(*read_argv) = tmp;
	}
	else if (check_env_name(*read_argv) && (*read_argv)[tilda_i - 1] == '=')
	{
		if (!(*read_argv)[tilda_i + 1])
		{
			start = ft_piecestrcpy(*read_argv, 0, tilda_i - 1)	;
			*read_argv = ft_strjoin(start, home);
		}
//		else if ()
	}
}

static void		to_env_change(char **read_argv, char **env, int dollar_i)
{
	int end;
	char *to_change;
	char *rest;
	char *middle;

	end = dollar_i + 1;
	while ((*read_argv)[end] &&
			(ft_isalpha((*read_argv)[end]) || ((*read_argv)[end]) == '-'))
		end++;
	to_change = ft_piecestrcpy(*read_argv, dollar_i + 1, end);
	rest = ft_piecestrcpy(*read_argv, end, ft_strlen(*read_argv));
	(*read_argv)[dollar_i] = '\0';
	middle = get_env_str(to_change, env);
	to_change = ft_nstrjoin(3, *read_argv, middle, rest);
	*read_argv = to_change;
}

static void 	dollar_parse(char **read_argv, char **argv, int argc, char **env)
{
	int dollar_i;

	dollar_i = ft_chrsetcmp(*read_argv, "$");
	while (dollar_i >= 0 && ft_strlen((*read_argv)[dollar_i]) < dollar_i)
	{
		if (ft_isdigit((*read_argv)[dollar_i + 1]))
			to_argv_change(read_argv, argv, argc, dollar_i);
		else
			to_env_change(read_argv, env, dollar_i);
		dollar_i = ft_chrsetcmp(*read_argv, "$");
	}
}

static void		check_symbols(char ***read_argv, char **argv, int argc, char **env)
{
	char 	*home;
	int 	dollar_i;
	int		tilda_i;
	int 	i;

	i = 0;
	home = get_env_str("HOME", env);
	while ((*read_argv)[i])
	{
		dollar_i = ft_chrsetcmp((*read_argv)[i], "$");
		if (dollar_i >= 0)
			dollar_parse(&((*read_argv)[i]), argv, argc, env);
		tilda_i = ft_chrsetcmp((*read_argv)[i], "~");
		if (home && tilda_i >= 0)
			to_home_change(&((*read_argv)[i]), home, tilda_i);
		i++;
	}
}

char	**get_parse(char **argv, int argc, char *read_buf, char **env)
{
	char	**read_argv;

	read_argv = ft_strcharsetsplit(read_buf, " \n\t");
	check_symbols(&read_argv, argv, argc, env);
	return (read_argv);
}