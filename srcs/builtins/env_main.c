/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:16:34 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:16:36 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		env_main(char **argv, char ***env)
{
	char **env_cpy;

	if (!env || !*env)
		return (0);
	env_cpy = *env;
	while (*env_cpy)
	{
		ft_putendl(*env_cpy);
		env_cpy++;
	}
	(void)argv;
	return (0);
}
