//
// Created by slavanya on 26.04.2020.
//

#include "minishell.h"
#include "libft_minishell.h"

static void check_symbols(char ***read_argv, char **argv, char **env)
{
	int 	i;
	char	*home;
	int 	tilda_i;

	i = 0;
	home = get_env_str("HOME", env);
	while ((*read_argv)[i])
	{
		dollar_esc(&((*read_argv)[i]), argv, env);
		tilda_i = ft_chrsetcmp(((*read_argv)[i]), "~");
		if (tilda_i >= 0 && home)
			tilda_esc(&((*read_argv)[i]), home, tilda_i);
		i++;
	}
}

char **get_parse(char **argv, char *read_buf, char **env)
{
	char	**read_argv;

	read_argv = ft_strcharsetsplit(read_buf, " \n\t");
	check_symbols(&read_argv, argv, env);
	return (read_argv);
}