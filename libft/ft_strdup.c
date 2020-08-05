/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:11:59 by hlorrine          #+#    #+#             */
/*   Updated: 2019/10/03 21:47:56 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char const *src)
{
	char	*str;

	if (!(str = ft_strnew(ft_strlen(src))))
		return (NULL);
	return (ft_strcpy(str, src));
}
