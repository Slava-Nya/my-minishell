//
// Created by slavanya on 02.05.2020.
//

#include <libft.h>
#include <builtins.h>
#include "../libft_minishell/errors.h"
#include "../libft_minishell/libft_minishell.h"

static void setenv_argv(char *argv, char ***env, int equals_symb)
{
	int		env_argc;
	char	*env_name;
	char	**new_enw;

	env_name = ft_piecestrcpy(argv, 0, equals_symb - 1);
	if (get_env_str(env_name, *env) != NULL)
	{
		argv += (equals_symb + 1);
		change_env_str(env_name, argv, env);
	}
	else
	{
		env_argc = ft_arraylen(*env);
		new_enw = ft_2darraycpy((*env), env_argc + 1);
		new_enw[env_argc] = ft_strdup(argv);
		(*env) = new_enw;
	}
}

int 	setenv_main(char **argv, char ***env)
{
	int argc;
	int cnt;
	int equals_symb;

	argc = ft_arraylen(argv);
	if (argc == 1)
		env_main(argv, env);
	cnt = 1;
	while (cnt < argc)
	{
		equals_symb = check_env_name(argv[cnt]);
		if (equals_symb)
			setenv_argv(argv[cnt], env, equals_symb);
		else
			puterror(env_invalid_id, argv[cnt], "setenv");
		cnt++;
	}
	return (0);
}