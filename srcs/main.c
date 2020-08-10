/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:15:10 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:15:18 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		free_read_argv(char ***read_argv)
{
	int i;

	i = 0;
	while ((*read_argv)[i])
	{
		free((*read_argv)[i]);
		i++;
	}
	free(*read_argv);
}

int				main(int argc, char **argv, char **env)
{
	char	read_buf[BUF];
	char	**read_argv;
	char	**env_cpy;
	int		red;

	env_cpy = ft_2darraycpy(env, ft_arraylen(env));
	red = 1;
	argc = 0;
	while (1)
	{
		write(1, "$> ", 3);
		red = read(0, read_buf, BUF);
		read_buf[red] = '\0';
		read_argv = get_parse(argv, read_buf, env_cpy);
		if (*read_argv && **read_argv)
			get_execute(read_argv, &env_cpy);
		free_read_argv(&read_argv);
	}
}
