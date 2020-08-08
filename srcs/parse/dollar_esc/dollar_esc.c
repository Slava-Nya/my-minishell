//
// Created by slavanya on 06.06.2020.
//
#include "minishell.h"

static void 	dollar_change(char **read_argv, char **argv, char **env, int dollar_i)
{
	char *begin;
	char *middle;
	char *end;
	int end_of_middle;

	dollar_get_begin(read_argv, &begin, dollar_i);
	end_of_middle = dollar_get_end(read_argv, &end, dollar_i);
	middle = dollar_get_middle(read_argv, argv, env, end_of_middle);
	free(*read_argv);
	*read_argv = ft_nstrjoin(3, begin, middle, end);
	free(begin);
	free(middle);
	free(end);
}

void dollar_esc(char **read_argv, char **argv, char **env)
{
	int dollar_i;

	dollar_i = ft_chrsetcmp(*read_argv, "$");
	while (dollar_i >= 0 && (int)(ft_strlen(*read_argv)) > (dollar_i))
	{
		dollar_change(read_argv, argv, env, dollar_i);
		dollar_i = ft_chrsetcmp(*read_argv, "$");
	}
}