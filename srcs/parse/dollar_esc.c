//
// Created by slavanya on 06.06.2020.
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

static void 	dollar_esc(char **read_argv, char **argv, int argc, char **env)
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

static void 	get_begin(char **read_argv, char **begin, int dollar_i)
{
	if (dollar_i == 0)
		*begin = ft_xmalloc(0);
	else
		*begin = ft_piecestrcpy(*read_argv, 0, dollar_i - 1);
}

static int 	get_end(char **read_argv, char **end, int dollar_i)
{
	int invalid_symb;

	if (ft_isalpha((*read_argv)[dollar_i + 1]))
	{
		*end = ft_piecestrcpy(*read_argv, dollar_i + 1, ft_strlen(*read_argv));
		return (0);
	}
	invalid_symb = 0;
	while ((*read_argv)[invalid_symb])
	{
		if (!(ft_isalpha((*read_argv)[invalid_symb]))
			&& !(ft_isalpha((*read_argv)[invalid_symb])
			&& (*read_argv)[invalid_symb] != '_'))
			break ;
		invalid_symb++;
	}
	*end = ft_piecestrcpy(*read_argv, invalid_symb, ft_strlen(*read_argv));
	return (invalid_symb);
}

static void 	get_middle(char **read_argv, char **end, int dollar_i, int dollar_end)
{
	if (ft_isalpha((*read_argv)[dollar_i + 1]))
	{

	}

}

static void 	dollar_change(char **read_argv, char **argv, char **env, int dollar_i)
{
	char *begin;
	char *middle;
	char *end;
	int dollar_end;

	get_begin(read_argv, &begin, dollar_i);
	dollar_end = get_end(*read_argv, &end, dollar_i);
	get_middle(*read_argv, &middle, dollar_i, dollar_end);
	//is_alfa ? get_argv : get_env

}

void			dollar_esc(char **read_argv, char **argv, int argc, char **env)
{
	int dollar_i;

	dollar_i = ft_chrsetcmp(*read_argv, "$");
	while (dollar_i >= 0 && ft_strlen((*read_argv)[dollar_i]) < dollar_i)
	{
		dollar_change(*read_argv, argv, env, dollar_i);
		dollar_i = ft_chrsetcmp(*read_argv, "$");
	}
}