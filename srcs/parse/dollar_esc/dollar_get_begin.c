/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_get_begin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:15:44 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:15:47 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dollar_get_begin(char **read_argv, char **begin, int dollar_i)
{
	if (dollar_i == 0)
		*begin = ft_strnew(0);
	else
		*begin = ft_piecestrcpy(*read_argv, 0, dollar_i - 1);
}
