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
char **env, int dollar_i)
{
	char			*begin;
	char			*middle;
	char			*end;
	t_section		sec;

	sec.dollar_i = dollar_i;
	dollar_get_begin(read_argv, &begin, sec.dollar_i);
	sec.invalid_symb = dollar_get_end(read_argv, &end, sec.dollar_i);
	middle = dollar_get_middle(read_argv, argv, env, sec);
	free(*read_argv);
	*read_argv = ft_nstrjoin(3, begin, middle, end);
	free(begin);
	free(middle);
	free(end);
}

static int		get_dollar_cnt(char **read_argv)
{
	int i;
	int dollar_cnt;

	dollar_cnt = 0;
	i = 0;
	while ((*read_argv)[i])
	{
		if ((*read_argv)[i] == '$')
			dollar_cnt++;
		i++;
	}
	return (dollar_cnt);
}

void			dollar_esc(char **read_argv, char **argv, char **env)
{
	int len;
	int dollar_i;
	int dollar_cnt;
	int i;

	dollar_cnt = get_dollar_cnt(read_argv);
	len = ft_strlen(*read_argv);
	i = 0;
	while (i < len)
	{
		if (*read_argv && **read_argv &&\
		(*read_argv)[i] == '$' && dollar_cnt > 0)
		{
			dollar_i = i;
			dollar_change(read_argv, argv, env, dollar_i);
			dollar_cnt--;
			i = 0;
		}
		i++;
		len = ft_strlen(*read_argv);
	}
}
