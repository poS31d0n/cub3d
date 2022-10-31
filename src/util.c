#include "cub3d.h"

int ft_compare(char *str, char *str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(str[i] && str2[j])
	{
		if (str[i] == str2[j])
		{
			while(str[i] && str2[j])
			{
				if (str2[j] == '\0')
					break;
				if (str[i] != str2[j])
					return (-1);
				i++;
				j++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}
 
 void error(t_vector vector)
 {
	printf("Error\n");
	ft_free(vector);
	exit (0);
 }

void errormap(t_vector vector, char **map)
 {
	printf("Error\n");
	ft_free_chartable(map);
	ft_free(vector);
	exit (0);
 }

 int valid(int bool, t_vector vector)
{
	if (bool)
		error(vector);
	bool = 1;
	return (bool);
}
