/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_get_middle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:15:57 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:16:02 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_minishell.h"
#include "minishell.h"

static char		*on_env_change(char **read_argv, char **env,\
int dollar_i, int end_of_middle)
{
	char *env_name;
	char *tmp;
	char *middle;

	env_name = ft_piecestrcpy(*read_argv, dollar_i + 1, end_of_middle - 1);
	if ((tmp = get_env_str(env_name, env)) == NULL)
		middle = ft_strnew(0);
	else
		middle = ft_strdup(tmp);
	free(env_name);
	return (middle);
}

char			*dollar_get_middle(char **read_argv, char **argv,\
char **env, t_section sec)
{
	char	*middle;
	int		argv_index;

	middle = NULL;
	if (ft_isdigit((*read_argv)[sec.dollar_i + 1]) &&
		argv[(int)((*read_argv)[sec.dollar_i + 1])])
	{
		argv_index = (*read_argv)[sec.dollar_i + 1] - '0';
		if (argv_index < ft_arraylen(argv))
			middle = ft_strdup(argv[argv_index]);
		else
			middle = ft_strnew(0);
	}
	else if (ft_isalpha((int)((*read_argv)[sec.dollar_i + 1])))
		middle = on_env_change(read_argv, env, sec.dollar_i, sec.invalid_symb);
	else
		middle = ft_strnew(0);
	return (middle);
}
