//
// Created by slavanya on 02.05.2020.
//

#include <libft.h>

int 	echo_main(char **line_argv, char ***env)
{
	int 	i;

	i = 1;
	while (line_argv[i])
	{
		ft_putstr(line_argv[i]);
		if (line_argv[i + 1])
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (1);
}
