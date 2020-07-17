//
// Created by slava-nya on 6/14/20.
//

#include <libft.h>
#include "../../libft_minishell/libft_minishell.h"

char	*dollar_get_middle(char **read_argv, char **argv, char **env, int end_of_middle)
{
	int dollar_i;
	char *middle;
	char *env_name;

	dollar_i = ft_chrsetcmp(*read_argv, "$");
	ft_putstr(argv[dollar_i + 1]);
	if (ft_isdigit((*read_argv)[dollar_i + 1]) &&
		argv[((*read_argv)[dollar_i + 1])])
	{
		middle = ft_strdup(argv[(*read_argv)[dollar_i + 1]]);
	}
	else if (ft_isalpha((*read_argv)[dollar_i + 1]))
	{
		env_name = ft_piecestrcpy(*read_argv, dollar_i + 1, end_of_middle - 1);
		middle = get_env_str(env_name, env);
	}
	if (!middle)
		middle = ft_strnew(0);
	return (middle);
}