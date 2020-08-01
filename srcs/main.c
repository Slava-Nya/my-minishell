/*
 * переписать strsplit
 *
 */

#include "minishell.h"

 /*
  * unsetenv удаление строки
  */

 int		main(int argc, char  **argv, char **env)
{
	char read_buf[BUF];
	char **read_argv;
	char **env_cpy;
	int red;

	env_cpy = ft_2darraycpy(env, ft_arraylen(env));
	red = 1;
	argc = 0;
	while (1)
	{
		write(1, "$> ", 3);
		red = read(0, read_buf, BUF);
		read_buf[red] = '\0';
		read_argv = get_parse(argv, read_buf, env_cpy);
		if (*read_argv)
			get_execute(read_argv, &env_cpy);
	}
}