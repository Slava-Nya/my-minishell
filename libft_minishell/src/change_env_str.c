/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:31:15 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:31:19 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_minishell.h"

int			change_env_str(char *env_name, char *new_str, char ***env)
{
	int	env_name_len;
	int count;

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
