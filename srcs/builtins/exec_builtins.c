/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:16:39 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:16:42 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtins.h"

int		exec_builtins(char **read_argv, char ***env)
{
	int i;

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
