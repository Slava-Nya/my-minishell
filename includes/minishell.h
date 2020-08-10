/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:34:47 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:34:51 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUF 1024
# define MAX_PATH 256
# include "libft.h"

struct						s_section{
	int		dollar_i;
	int		invalid_symb;
};

typedef struct s_section	t_section;

int							main(int argc, char **argv, char **env);
char						**get_parse(char **argv, char *read_buf,\
char **env);

void						get_execute(char **read_argv, char ***env);
char						*try_exec_bins(char **read_argv, char **env_paths,\
char *full_env_path);

void						tilda_esc(char **read_argv, char *home,\
int tilda_i);

void						dollar_esc(char **read_argv, char **argv,\
char **env);
void						dollar_get_begin(char **read_argv, char **begin,\
int dollar_i);
char						*dollar_get_middle(char **read_argv, char **argv,\
char **env, t_section sec);
int							dollar_get_end(char	**read_argv, char **end,\
int dollar_i);

#endif
