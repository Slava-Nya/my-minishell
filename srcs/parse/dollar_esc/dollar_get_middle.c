//
// Created by slava-nya on 6/14/20.
//

#include "libft.h"
#include "libft_minishell.h"

static char *on_env_change(char **read_argv, char **env, int dollar_i, int end_of_middle)
{
	char *env_name;
	char *tmp;
	char *middle;

	env_name = ft_piecestrcpy(*read_argv, dollar_i + 1, end_of_middle - 1);
	if ((tmp = get_env_str(env_name, env)) == NULL)
		middle = ft_strnew(0);
	else
		middle = ft_strdup(tmp);
	free(env_name);
	return (middle);
}

char	*dollar_get_middle(char **read_argv, char **argv, char **env, int end_of_middle)
{
	int dollar_i;
	char *middle;
	int argv_index;

	middle = NULL;
	dollar_i = ft_chrsetcmp(*read_argv, "$");
	if (ft_isdigit((*read_argv)[dollar_i + 1]) &&
		argv[(int)((*read_argv)[dollar_i + 1])])
	{
		argv_index = (*read_argv)[dollar_i + 1] - '0';
		if (argv_index < ft_arraylen(argv))
			middle = ft_strdup(argv[argv_index]);
		else
			middle = ft_strnew(0);
	}
	else if (ft_isalpha((int)((*read_argv)[dollar_i + 1])))
		middle = on_env_change(read_argv, env, dollar_i, end_of_middle);
	else
		middle = ft_strnew(0);
	return (middle);
}