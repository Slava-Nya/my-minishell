/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:16:28 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:16:31 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		echo_main(char **line_argv, char ***env)
{
	int i;

	i = 1;
	while (line_argv[i])
	{
		ft_putstr(line_argv[i]);
		if (line_argv[i + 1])
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	(void)env;
	return (1);
}
