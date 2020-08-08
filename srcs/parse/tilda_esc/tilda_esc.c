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

static int		get_begin(char **begin, char **read_argv, int tilda_i)
{
	if (tilda_i == 0 && (*read_argv)[1] == '/')
		*begin = ft_strnew(0);
	else if (check_env_name(*read_argv) && (*read_argv)[tilda_i - 1] == '=')
		*begin = ft_piecestrcpy(*read_argv, 0, tilda_i - 1);
	else
		return (0);
	return (1);
}

void			tilda_esc(char **read_argv, char *home, int tilda_i)
{
	char *begin;
	char *end;

	begin = NULL;
	end = NULL;
	if (!(*read_argv)[1])
	{
		free(*read_argv);
		*read_argv = ft_strdup(home);
	}
	else
	{
		if (!(get_begin(&begin, read_argv, tilda_i)))
			return ;
		if (!(get_end(&end, read_argv, tilda_i)))
			return ;
		*read_argv = ft_nstrjoin(3, begin, home, end);
		free(begin);
		free(end);
	}
}
