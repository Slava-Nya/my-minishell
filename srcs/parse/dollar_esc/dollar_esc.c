//
// Created by slavanya on 06.06.2020.
//

#include <minishell.h>
#include "../../libft_minishell/libft_minishell.h"




static void 	dollar_change(char **read_argv, char **argv, char **env, int dollar_i)
{
	char *begin;
	char *middle;
	char *end;
	int end_of_middle;

	dollar_get_begin(read_argv, &begin, dollar_i);
	end_of_middle = dollar_get_end(read_argv, &end, dollar_i);
//	ft_putendl(argv[(*read_argv)[dollar_i + 1] - '0']);
	middle = dollar_get_middle(read_argv, argv, env, end_of_middle);
	*read_argv = ft_nstrjoin(3, begin, middle, end);
}

void			dollar_esc(char **read_argv, char **argv, int argc, char **env)
{
	int dollar_i;

	dollar_i = ft_chrsetcmp(*read_argv, "$");
	int tmp = ft_strlen(*read_argv);
	while (dollar_i >= 0 && ft_strlen(*read_argv) > (dollar_i))
	{
		if (ft_isdigit((*read_argv)[dollar_i + 1]))
		{
			dollar_change(read_argv, argv, env, dollar_i);
		}
		dollar_i = ft_chrsetcmp(*read_argv, "$");
	}
}