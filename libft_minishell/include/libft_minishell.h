/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_minishell.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:32:08 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:32:15 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MINISHELL_H
# define LIBFT_MINISHELL_H
# define MAX_PATH 256
# include "libft.h"

char	**get_bin_paths(char **env);
char	*get_env_str(char *env_name, char **env);
int		change_env_str(char *env_name, char *new_str, char ***env);
void	get_full_path(char *full_path, char *start, char *end);
int		check_env_name(char *argv);

#endif
