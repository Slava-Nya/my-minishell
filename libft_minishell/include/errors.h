/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:32:02 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:32:04 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
#define ERRORS_H
#define N_ERRORS 7

enum e_error{
	false_command,
	cd_no_file,
	cd_no_rules,
	cd_not_dir,
	cd_long_name,
	env_not_set,
	env_invalid_id,
};

typedef enum e_error t_error;

static char *error_map_str[N_ERRORS] = {
		"command not found",
		"no such file or directory",
		"permission denied",
		"not a directory",
		"file name too long",
		"not set",
		"not a valid identifier",
};

void 	puterror(int errno, char *argv, char *builtin);

//void print_error(int code);

//ft_putstr_fd(error_map_str[code], 2);

#endif //ERRORS_H


//print_error(e_ne_ok);
