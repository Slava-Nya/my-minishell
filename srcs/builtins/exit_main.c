//
// Created by slavanya on 02.05.2020.
//

#include "builtins.h"

int 	exit_main(char **argv, char ***env)
{
	(void)env;
	(void)argv;
	exit(0);
}