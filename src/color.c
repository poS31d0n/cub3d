#include "cub3d.h"

char *make_tmp(int i, int j, char **map)
{
	char *tmp;
	int l;
	l = 0;
	while (map[i][j++])
		l++;
	tmp = malloc(sizeof(char *) * (l + 1));
	return (tmp);
}

void freetmp2(int i, int j, char *tmp, char **map, t_vector vector)
{
	if (map[i][j + 1] == ' ' || !map[i][j + 1])
		{
			free(tmp);
			errormap(vector, map);
		}
}

int *colors(int *object, char **map, int i, t_vector vector)
{
	int j;
	int l;
	int h;
	char *tmp;

	object = malloc(sizeof(int *) * 3);
	j = 0;
	tmp = make_tmp(i, j, map);
	j = 2;
	l = 0;
	h = 0;
	while(map[i][j] != '\0')
	{
		if (map[i][j] == ',')
		{
			freetmp2(i, j++, tmp, map, vector);
			object[h++] = ft_atoi(tmp);
			free(tmp);
			tmp = make_tmp(i ,j, map);
			l = 0;
		}
		tmp[l++] = map[i][j++];
	}
	object = fillobj(h, tmp, vector, map, object);
	return(object);
}

t_vector valid_colors(char **map, t_vector vector)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(map[i])
	{
		if (ft_compare(map[i], "F") == 1)
		{
			vector.floor = colors(vector.floor, map, i, vector);
		}
		if (ft_compare(map[i], "C") == 1)
		{
			vector.celling = colors(vector.celling, map, i, vector);
			vector.pos = i + 1;
		}
		i++;
	}
	if (vector.celling == NULL || vector.floor == NULL)
		errormap(vector, map);
	while (vector.celling[j] && vector.floor[j])
		j++;
	if (j < 2)
		errormap(vector, map);
	return (vector);
}
