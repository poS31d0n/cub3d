#include "cub3d.h"

char *objects(char *str, char**map, int i)
{
	int l;
	int j;

	j = 0;
	l = 0;
	while (map[i][j])
		j++;
	str = malloc(sizeof(char *) * (j + 1));
	j = 0;
	while(map[i][j])
	{
		if(map[i][j] == '.')
		{
			while(map[i][j])
			{
				str[l] = map[i][j];
				l++;
				j++;
			}
			return (str);
		}
		j++;
	}
	free(str);
	return(NULL);
}
t_vector valid_objects(char **map, t_vector vector)
{
	int i;
	i = 0;
	while(map[i])
	{
		if (ft_compare(map[i], "NO ./") == 1)
			vector.north = objects(vector.north, map, i);
		
		if (ft_compare(map[i], "SO ./") == 1)
			vector.south = objects(vector.south, map, i);

		if (ft_compare(map[i], "WE ./") == 1)
			vector.west = objects(vector.west, map, i);

		if (ft_compare(map[i], "EA ./") == 1)
			vector.east = objects(vector.east, map, i);
		i++;
	}
	if (vector.north == NULL || vector.south == NULL || vector.east == NULL|| vector.west == NULL)
		errormap(vector, map);
	return(vector);
}
