/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:16:44 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:16:47 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "libft.h"

int		exit_main(char **argv, char ***env)
{
	(void)env;
	if (ft_arraylen(argv) >= 2)
		exit(ft_atoi(argv[1]));
	else
		exit(0);
}
