//
// Created by slavanya on 04.05.2020.
//

#include "libft_minishell.h"
#include "errors.h"

void 	puterror(int errno, char *argv, char *builtin)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(builtin, 2);
	ft_putstr_fd(": ", 2);
	if (*argv)
		ft_putstr_fd(argv, 2);
	if (*argv)
		ft_putstr_fd(": ", 2);
	ft_putendl_fd(error_map_str[errno], 2);
}