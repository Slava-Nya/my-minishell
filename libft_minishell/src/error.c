/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:31:28 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:31:31 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_minishell.h"
#include "errors.h"

void	puterror(int errno, char *argv, char *builtin)
{
	static const char		*error_map_str[N_ERRORS] = {
			"command not found",
			"no such file or directory",
			"permission denied",
			"file name too long",
			"not a valid identifier",
	};

	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(builtin, 2);
	ft_putstr_fd(": ", 2);
	if (*argv)
		ft_putstr_fd(argv, 2);
	if (*argv)
		ft_putstr_fd(": ", 2);
	ft_putendl_fd(error_map_str[errno], 2);
}
