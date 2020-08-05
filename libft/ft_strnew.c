/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:33:49 by hlorrine          #+#    #+#             */
/*   Updated: 2019/10/03 23:07:32 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	if (size + 1 == 0)
		return (NULL);
	ptr = (char*)ft_xmalloc(sizeof(char) * (size + 1));
	ft_memset(ptr, '\0', size + 1);
	return (ptr);
}
