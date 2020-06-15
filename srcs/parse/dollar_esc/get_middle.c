//
// Created by slava-nya on 6/14/20.
//

#include <libft.h>

void 	get_middle(char **read_argv, char **argv, char **env, int end_of_middle)
{
	int dollar_i;
	char *env_name;
	dollar_i = ft_chrsetcmp(*read_argv, "$");

}



//if (ft_isdigit((*read_argv)[dollar_i + 1]))
//middle = argv[(*read_argv)[dollar_i + 1]] ? ft_strdup(argv[(*read_argv)[dollar_i + 1]])
//										  : ft_strnew(0);
//else
//{
//env_name = ft_piecestrcpy(*read_argv, dollar_i + 1, end_of_middle);
//middle = get_env_str(env_name, env);
//if (!middle)
//middle = ft_strnew(0);
//}
//*read_argv = ft_nstrjoin(3, begin, middle, end);