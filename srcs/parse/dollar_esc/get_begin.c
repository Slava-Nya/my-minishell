//
// Created by slava-nya on 6/14/20.
//

#include <libft.h>

void 	dollar_get_begin(char **read_argv, char **begin, int dollar_i)
{
	if (dollar_i == 0)
		*begin = ft_strnew(0);
	else
		*begin = ft_piecestrcpy(*read_argv, 0, dollar_i - 1);
}
