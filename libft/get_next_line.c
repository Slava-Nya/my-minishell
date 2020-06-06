/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:15:29 by hlorrine          #+#    #+#             */
/*   Updated: 2019/11/18 20:16:37 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_createlem(t_lst *lst, int fd)
{
	t_lst *elem;
	t_lst *tmp;

	if (!(elem = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	elem->lst_fd = fd;
	if (!(elem->str = ft_strnew(1)))
		return (NULL);
	elem->next = NULL;
	tmp = lst;
	if (!lst)
		lst = elem;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	return (elem);
}

t_lst	*ft_list_exist(t_lst *lst, int actual_fd)
{
	t_lst	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->lst_fd == actual_fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (ft_createlem(lst, actual_fd));
}

int		ft_end(t_lst *tmp, char **line, int ret)
{
	char	*after_n;
	int		i;
	int		n;
	char	c;

	i = 0;
	while ((tmp->str)[i] && (tmp->str)[i] != '\n')
		i++;
	if (!(*line = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	(*line)[i] = '\0';
	ft_strncpy(*line, tmp->str, i);
	n = 1;
	c = '\n';
	if (ret == 0)
	{
		c = '\0';
	}
	if (!(after_n = ft_strdup(ft_strchr(tmp->str, c) + n)))
		return (-1);
	free(tmp->str);
	tmp->str = after_n;
	return (1);
}

int		ft_reader(char *buf, t_lst *tmp, int fd, int ret)
{
	char	*fun;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(fun = ft_strjoin(tmp->str, buf)))
			return (-1);
		free(tmp->str);
		tmp->str = fun;
		if (ft_strchr(buf, '\n') != NULL)
			break ;
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static t_lst	*lst;
	char			buf[BUFF_SIZE + 1];
	t_lst			*tmp;
	int				ret;

	if (!lst)
		lst = ft_createlem(lst, fd);
	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	tmp = ft_list_exist(lst, fd);
	ret = -2;
	if (!ft_strchr(tmp->str, '\n'))
		ret = ft_reader(buf, tmp, fd, ret);
	if (ret == -1)
		return (-1);
	if (ret == 0 && (!(tmp->str) || !(tmp->str)[0]))
		return (0);
	return (ft_end(tmp, line, ret));
}
