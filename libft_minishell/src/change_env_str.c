//
// Created by slavanya on 05.05.2020.
//

#include "libft_minishell.h"

int	change_env_str(char *env_name, char *new_str, char ***env)
{
	int 	env_name_len;
	int 	count;
	char	*env_cpy;

	env_name_len = ft_strlen(env_name);
	count = 0;
	while ((*env)[count])
	{
		if ((ft_strncmp(env_name, (*env)[count], env_name_len)) == 0)
		{
			(*env)[count][env_name_len] = '\0';
			env_cpy = ft_strdup((*env)[count]);
			(*env)[count] = ft_strjoin(env_cpy, new_str);
			free(env_cpy);
			return (count);
		}
		count++;
	}
	return (-1);
}