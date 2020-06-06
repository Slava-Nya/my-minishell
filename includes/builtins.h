//
// Created by slavanya on 02.05.2020.
//

#ifndef BUILTINS_H
#define BUILTINS_H

# define BUILTINS_CNT 6
# define MAX_PATH 256

#include "stdlib.h"

struct s_paths{
	char pwd[MAX_PATH];
	char *home;
	char *oldpwd;
};

typedef struct s_paths	t_paths;

struct	s_builtins{
	char 	*name;
	int 	(*f)(char **line_argv, char ***env);
};

int 	echo_main(char **line_argv, char ***env);
int 	cd_main(char **line_argv, char ***env);
int 	setenv_main(char **line_argv, char ***env);
int 	unsetenv_main(char **line_argv, char ***env);
int 	env_main(char **line_argv, char ***env);
int 	exit_main(char **line_argv, char ***env);

typedef struct s_builtins t_builtins ;

static const t_builtins g_builtins[BUILTINS_CNT] = {
		{"echo", &echo_main},
		{"cd", &cd_main},
		{"setenv", &setenv_main},
		{"unsetenv", &unsetenv_main},
		{"env", &env_main},
		{"exit", &exit_main}
};

int 	exec_builtins(char **read_argv, char ***env);

#endif //BUILTINS_H
