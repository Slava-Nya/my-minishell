//
// Created by slavanya on 31.05.2020.
//

static int 	check_env_name(char  *argv)
{
	int i;

	if ((!ft_isalpha(argv[0])) && argv[0] != '_')
		return (0);
	i = 1;
	while (argv[i])
	{
		if ((!ft_isalpha(argv[i])) && (!ft_isdigit(argv[i]))
			&& argv[i] != '_' && argv[i] != '=')
			return (0);
		if (argv[i] == '=')
			return (i);
		i++;
	}
	return (0);
}