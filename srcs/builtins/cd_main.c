//
// Created by slavanya on 02.05.2020.
//

#include "dirent.h"
#include "minishell.h"
#include "builtins.h"
#include "libft_minishell.h"
#include "errors.h"

static int	check_access(char *path)
{
	if (!path || access(path, F_OK) == -1)
	{
		puterror(cd_no_file, path, "cd");
		return(1);
	}
	else if (access(path, R_OK) == -1)
	{
		puterror(cd_no_rules, path, "cd");
		return (1);
	}
	else if (!opendir(path))
	{
		puterror(cd_not_dir, path, "cd");
		return (1);
	}
	else if(ft_strlen(path) > MAX_PATH)
	{
		puterror(cd_long_name, path, "cd");
		return (1);
	}
	return (0);
}

static void change_directory(char ***env, char *new_pwd, char *oldpwd)
{
	char pwd[MAX_PATH];

	ft_bzero(pwd, MAX_PATH);
	getcwd(pwd, MAX_PATH);;
	if (check_access(new_pwd))
		return ;
	else if (!oldpwd || new_pwd || pwd[0] == '\0')
	{
		//проверять переменные env
		return ;
	}
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
		change_directory(env, paths.home, paths.pwd);
	else if (argv[1][0] == '-' && !argv[1][1])
		change_directory(env, paths.oldpwd, paths.pwd);
	else
		change_directory(env, argv[1], paths.pwd);
	return (0);
}