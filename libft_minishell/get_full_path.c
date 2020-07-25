//
// Created by slavanya on 10.05.2020.
//

#include "libft_minishell.h"

void 	get_full_path(char *full_path, char *start, char *end)
{
	ft_bzero(full_path, MAX_PATH);
	ft_strncat(full_path, start, MAX_PATH);
	ft_strncat(full_path, "/", MAX_PATH);
	ft_strncat(full_path, end, MAX_PATH);
}