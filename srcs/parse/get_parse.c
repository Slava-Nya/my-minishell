//
// Created by slavanya on 26.04.2020.
//

#include <minishell.h>
#include "../libft_minishell/libft_minishell.h"

static void		check_symbols(char ***read_argv, char **argv, int argc, char **env)
{
	int 	i;
	char	*home;
	int 	tilda_i;

	i = 0;
	home = get_env_str("HOME", env);
	while (i < argc)
	{
		dollar_esc(&((*read_argv)[i]), argv, argc, env);
		tilda_i = ft_chrsetcmp(&((*read_argv)[i]), "~");
		if (tilda_i >= 0 && home)
			tilda_esc(&((*read_argv)[i]), home, tilda_i);
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