//
// Created by slavanya on 11.05.2020.
//

#include "libft.h"

char 	*ft_piecestrcpy(char *s, int start, int end)
{
	char *new;
	int i;

	i = 0;
	if (!*s || start > end || ft_strlen(s) < (end - start))
		new = ft_xmalloc(0);
	new = ft_xmalloc(sizeof(char *) * (end - start + 1));
	while (start <= end)
	{
		new[i] =  s[start];
		start++;
		i++;
	}
	return (new);
}