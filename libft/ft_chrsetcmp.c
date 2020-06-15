//
// Created by slavanya on 10.05.2020.
//

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