/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:31:35 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:31:37 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_minishell.h"

char	**get_bin_paths(char **env)
{
	char *bins_full_path;
	char **bins_paths;

	if (check_env_name("PATH"))
		return (NULL);
	bins_full_path = get_env_str("PATH", env);
	bins_paths = ft_strsplit(bins_full_path, ':');
	return (bins_paths);
}
