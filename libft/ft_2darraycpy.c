/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2darraycpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:32:31 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 16:32:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_2darraycpy(char **arr, int dest_len)
{
	char	**dest;
	int		len;
	int		i;

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
