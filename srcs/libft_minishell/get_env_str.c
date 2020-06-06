//
// Created by slavanya on 04.05.2020.
//

#include "libft_minishell.h"

char	*get_env_str(char *env_name, char **env)
{
	int 	env_name_len;
	int 	count;
	char 	*str;

	env_name_len = ft_strlen(env_name);
	count = 0;
	while (env[count])
	{
		if (ft_strncmp(env_name, env[count], env_name_len) == 0
			&& env[count][env_name_len + 1] == '=')
		{
			str = ft_strchr(env[count], '=');
			return (++str);
		}
		count++;
	}
	return (NULL);
}