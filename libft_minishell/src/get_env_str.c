/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:31:40 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:31:43 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			&& env[count][env_name_len] == '=')
		{
			str = ft_strchr(env[count], '=');
			return (++str);
		}
		count++;
	}
	return (NULL);
}
