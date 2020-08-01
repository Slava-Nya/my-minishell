//
// Created by slavanya on 02.05.2020.
//

#include "minishell.h"
#include "builtins.h"
#include "libft_minishell.h"
#include "errors.h"
/*
 * сделвть смену oldpwd
 */


static void		change_directory(char ***env, char *argv, char *new_pwd, char *oldpwd)
{
	char pwd[MAX_PATH];

	ft_bzero(pwd, MAX_PATH);
	getcwd(pwd, MAX_PATH);;
	if (!new_pwd)
		puterror(cd_no_file, argv, "cd");
	else if (chdir(new_pwd) == 0)
	{
		change_env_str("PWD=", new_pwd, env);
		change_env_str("OLDPWD=", oldpwd, env);
	}
	else
		puterror(cd_no_file, new_pwd, "cd");
}

static void		get_paths(char **env, t_paths *paths)
{
	ft_bzero(paths->pwd, MAX_PATH);
	getcwd(paths->pwd, MAX_PATH);
	paths->oldpwd = get_env_str("OLDPWD", env);
	paths->home = get_env_str("HOME", env);
}

int 	cd_main(char **argv, char ***env)
{
	int argc;
	t_paths paths;

	argc = ft_arraylen(argv);
	get_paths(*env, &paths);
	if (argc == 1)
		change_directory(env, "", paths.home, paths.pwd);
	else if (argv[1][0] == '-' && !argv[1][1])
		change_directory(env, argv[1], paths.oldpwd, paths.pwd);
	else
		change_directory(env, argv[1], argv[1], paths.pwd);
	return (0);
}