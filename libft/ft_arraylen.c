//
// Created by slavanya on 04.05.2020.
//

int 	ft_arraylen(char **array)
{
	int 	len;

	len = 0;
	if (!array)
		return (0);
	while (array[len])
		len++;
	return (len);
}