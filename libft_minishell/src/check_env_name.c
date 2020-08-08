/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:31:22 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:31:24 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_minishell.h"

int		check_env_name(char *argv)
{
	int i;

	if ((!ft_isalpha(argv[0])) && argv[0] != '_')
		return (0);
	i = 1;
	while (argv[i])
	{
		if ((!ft_isalpha(argv[i])) && (!ft_isdigit(argv[i]))
			&& argv[i] != '_' && argv[i] != '=')
			return (0);
		if (argv[i] == '=')
			return (i);
		i++;
	}
	return (0);
}
