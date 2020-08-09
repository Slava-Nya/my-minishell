/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_esc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:15:38 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:15:41 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		dollar_change(char **read_argv, char **argv,\
char **env, int section[2])
{
	char	*begin;
	char	*middle;
	char	*end;

	dollar_get_begin(read_argv, &begin, section[0]);
	section[1] = dollar_get_end(read_argv, &end, section[0]);
	middle = dollar_get_middle(read_argv, argv, env, section);
	free(*read_argv);
	*read_argv = ft_nstrjoin(3, begin, middle, end);
	free(begin);
	free(middle);
	free(end);
}

void			dollar_esc(char **read_argv, char **argv, char **env)
{
	int section[2];
	int len;

	len = ft_strlen(*read_argv);
	section[0] = 0;
	section[1] = 0;
//	free(*read_argv);
//	*read_argv = ft_strnew(0);
	while (section[0] < len)
	{
		if ((*read_argv)[section[0]] == '$' && len > (section[0]))
			dollar_change(read_argv, argv, env, section);
		(section[0])++;
	}
}
