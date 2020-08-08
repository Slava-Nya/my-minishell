/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:33:14 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:33:17 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

char			*ft_nstrjoin(int n, ...)
{
	va_list		args;
	size_t		len;
	int			ncpy;
	char		*str;

	len = 0;
	ncpy = n;
	va_start(args, n);
	while (n--)
		len += ft_strlen(va_arg(args, char *));
	va_end(args);
	if (!(str = ft_strnew(len)))
		return (NULL);
	va_start(args, n);
	while (ncpy--)
		str = ft_strcat(str, va_arg(args, char *));
	va_end(args);
	return (str);
}
