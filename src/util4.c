#include "cub3d.h"

t_vector newmapp(char **map, int i, int tmp, int tmp2, t_vector vector)
{
	tmp2 = i - tmp;
	vector.newmap = malloc(sizeof(char *) * (tmp + 1));
	if (!vector.newmap)
		exit(1);
	i = 0;
	while (map[tmp2] && i < tmp)
	{
		vector.newmap[i] = map[tmp2];
		tmp2++;
		i++;
	}
	return(vector);
}

t_vector *finder(int tmp, t_vector *vector, char *str)
{
	int j;
	int i;
	char s;

	i = 0;
	s = *str;
	while (vector->newmap[i] && i < tmp)
	{

		if (ft_compare(vector->newmap[i], str))
		{
			vector->y = i + 0.5;
			j = 0;
			while(vector->newmap[i][j])
			{
				if (vector->newmap[i][j] == s)
					vector->x = j + 0.5;
				j++;
			}
			return (vector);
		}
		i++;
	}
	return (NULL);
}

int	ft_sign(int d)
{
	//Надо понять для чего это надо
	return (d);
}

