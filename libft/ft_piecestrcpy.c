/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piecestrcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:33:19 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:33:22 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_piecestrcpy(char *s, int start, int end)
{
	char	*new;
	int		i;

	i = 0;
	if (!*s || start >= end || (int)ft_strlen(s) < end)
	{
		new = ft_strnew(0);
		return (new);
	}
	new = ft_xmalloc(sizeof(char *) * (end - start + 1));
	while (start <= end)
	{
		new[i] = s[start];
		start++;
		i++;
	}
	return (new);
}
