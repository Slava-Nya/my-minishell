//
// Created by slavanya on 05.05.2020.
//

#include <libft.h>

char **ft_2darraycpy(char **arr, int dest_len)
{
	char **dest;
	int len;
	int i;

	len = 0;
	i = 0;
	if (!arr || !(*arr))
		return (NULL);
	len = ft_arraylen(arr);
	if (dest_len < len)
		return (NULL);
	dest = ft_xmalloc(sizeof(char *) * (dest_len + 1));
	dest[dest_len] = NULL;
	while (i < len)
	{
		dest[i] = ft_strdup(arr[i]);
		i++;
	}
	return (dest);
}