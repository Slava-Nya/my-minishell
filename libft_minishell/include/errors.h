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
# define ERRORS_H
# define N_ERRORS 5

enum					e_error
{
	false_command,
	cd_no_file,
	no_rules,
	cd_long_name,
	env_invalid_id,
};

typedef enum e_error	t_error;

void					puterror(int errno, char *argv, char *builtin);

#endif
