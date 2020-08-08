/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:46:58 by hlorrine          #+#    #+#             */
/*   Updated: 2020/08/08 18:47:02 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_xmalloc(size_t size)
{
	void *ret;

	if (!(ret = ft_memalloc(size)))
	{
		ft_putstr_fd("out of memory puterror, exiting...", 2);
		exit(12);
	}
	return (ret);
}
