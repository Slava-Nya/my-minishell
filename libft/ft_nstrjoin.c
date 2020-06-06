//
// Created by slavanya on 09.05.2020.
//

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