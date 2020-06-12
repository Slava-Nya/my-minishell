//
// Created by slavanya on 06.06.2020.
//

#include <minishell.h>
#include "../libft_minishell/libft_minishell.h"

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

static void 	dollar_change(char **read_argv, char **argv, char **env, int dollar_i)
{
	char *begin;
	char *middle;
	char *end;
	char *env_name;
	int end_of_middle;

	get_begin(read_argv, &begin, dollar_i);
	end_of_middle = get_end(*read_argv, &end, dollar_i);
	if (ft_isalpha((*read_argv)[dollar_i + 1]))
		middle = argv[dollar_i + 1] ? ft_strdup(argv[dollar_i + 1])
				: ft_xmalloc(0);
	else
	{
		env_name = ft_piecestrcpy(*read_argv, dollar_i + 1, end_of_middle);
		middle = get_env_str(env_name, env);
		if (!middle)
			middle = ft_xmalloc(0);
	}
	*read_argv = ft_nstrjoin(3, begin, middle, end);
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