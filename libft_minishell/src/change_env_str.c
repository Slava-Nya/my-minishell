//
// Created by slavanya on 05.05.2020.
//

#include "libft_minishell.h"

int	change_env_str(char *env_name, char *new_str, char ***env)
{
	int 	env_name_len;
	int 	count;

	env_name_len = ft_strlen(env_name);
	count = 0;
	while ((*env)[count])
	{
		if ((ft_strncmp(env_name, (*env)[count], env_name_len)) == 0)
		{
			free((*env)[count]);
			(*env)[count] = ft_strjoin(env_name, new_str);
			return (count);
		}
		count++;
	}
	return (-1);
}