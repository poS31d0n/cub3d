#include "inc/cub3d.h"

void	ft_free_chartable(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void ft_free(t_vector vector)
{
	free(vector.north);
	free(vector.south);
	free(vector.west);
	free(vector.east);
	free(vector.floor);
	free(vector.celling);
	exit (1);
}

t_vector ft_init(t_vector vector)
{
	vector.x = 0;
	vector.y = 0;
	vector.north = NULL;
	vector.south = NULL;
	vector.east = NULL;
	vector.west = NULL;
	vector.floor = NULL;
	vector.celling = NULL;
	return (vector);
}

int *fillobj(int h, char *tmp, t_vector vector, char **map, int *object)
{
	freetmp(h, tmp, vector, map);
	object[h] = ft_atoi(tmp);
	free(tmp);
	return(object);
}
