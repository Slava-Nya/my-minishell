/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilda_esc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:15:31 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:15:34 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "libft_minishell.h"

static int		get_end(char **end, char **read_argv, int tilda_i)
{
	if (!(*read_argv)[tilda_i + 1])
		*end = ft_strnew(0);
	else if ((*read_argv)[tilda_i + 1] == '/')
		*end = ft_piecestrcpy(*read_argv, tilda_i + 1, ft_strlen(*read_argv));
	else
		return (0);
	return (1);
}

void			tilda_esc(char **read_argv, char *home, int tilda_i)
{
	char *end;

	end = NULL;
	if (!(*read_argv)[1])
	{
		free(*read_argv);
		if (home)
			*read_argv = ft_strdup(home);
		else
			*read_argv = ft_strnew(0);
	}
	else
	{
		get_end(&end, read_argv, tilda_i);
		free(*read_argv);
		if (home)
			*read_argv = ft_strjoin(home, end);
		else
			*read_argv = ft_strdup(end);
		free(end);
	}
}
