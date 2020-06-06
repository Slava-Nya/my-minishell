//
// Created by slavanya on 02.05.2020.
//

#include <libft.h>

void *ft_xmalloc(size_t size)
{
	void *ret;

	if (!(ret = ft_memalloc(size)))
	{
		ft_putstr_fd("out of memory puterror, exiting...", 2);
		exit(12);
	}
	return (ret);
}