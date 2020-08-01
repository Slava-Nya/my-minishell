//
// Created by slavanya on 02.05.2020.
//

#include "libft.h"

int 	env_main(char **argv, char ***env)
{
	char **env_cpy;

	if (!env || !*env)
		return (0);
	env_cpy = *env;
	while (*env_cpy)
	{
		if ((*env_cpy)[0])
			ft_putendl(*env_cpy);
		env_cpy++;
	}
	(void)argv;
	return (0);
}