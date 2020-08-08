/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:31:52 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:31:56 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_minishell.h"

void		get_full_path(char *full_path, char *start, char *end)
{
	ft_bzero(full_path, MAX_PATH);
	ft_strncat(full_path, start, MAX_PATH);
	ft_strncat(full_path, "/", MAX_PATH);
	ft_strncat(full_path, end, MAX_PATH);
}
