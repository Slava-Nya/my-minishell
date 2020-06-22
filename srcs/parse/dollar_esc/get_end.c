//
// Created by slava-nya on 6/14/20.
//

#include <libft.h>

int 	dollar_get_end(char **read_argv, char **end, int dollar_i)
{
	int invalid_symb;

	if (ft_isdigit((*read_argv)[dollar_i + 1]) > 0)
	{
		*end = ft_piecestrcpy(*read_argv, dollar_i + 2, ft_strlen(*read_argv));
		return (0);
	}
	invalid_symb = dollar_i + 1;
	while ((*read_argv)[invalid_symb])
	{
		if (!(ft_isalpha((*read_argv)[invalid_symb]))
			&& !(ft_isalpha((*read_argv)[invalid_symb])
				 && (*read_argv)[invalid_symb] != '_'))
			break ;
		invalid_symb++;
	}
	*end = ft_piecestrcpy(*read_argv, invalid_symb, ft_strlen(*read_argv));
	return (invalid_symb);
}