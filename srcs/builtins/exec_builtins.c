//
// Created by slavanya on 02.05.2020.
//


#include "libft.h"
#include "builtins.h"

int 	exec_builtins(char **read_argv, char ***env)
{
	int 	i;

	i = 0;
	while (i < BUILTINS_CNT)
	{
		if (!(ft_strcmp(read_argv[0], g_builtins[i].name)))
		{
			g_builtins[i].f(read_argv, env);
			return (1);
		}
		i++;
	}
	return (0);
}