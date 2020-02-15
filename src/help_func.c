#include "../includes/corewar.h"

int			ft_max_min_int(char *buff)
{
	if (*buff != '-' && ft_strlen(buff) == ft_strlen("2147483647"))
	{
		if (ft_strcmp(buff, "2147483647") > 0)
			return (0);
	}
	else if (*buff != '-' && ft_strlen(buff) > ft_strlen("2147483647"))
		return (0);
	else if (ft_strlen(buff) == ft_strlen("-2147483648"))
	{
		if (ft_strcmp(buff, "-2147483648") > 0)
			return (0);
	}
	else if (ft_strlen(buff) > ft_strlen("-2147483648"))
		return (0);
	return (1);
}

int			is_cor(char *av)
{
	if (av && ft_strstr(av, ".cor") && (ft_strlen(av) >= 4))
		return (1);
	return (0);
}