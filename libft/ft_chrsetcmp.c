/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrsetcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:32:47 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:32:49 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrsetcmp(char const *s, char *chrset)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (chrset[j])
		{
			if (s[i] == chrset[j])
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (-1);
}
