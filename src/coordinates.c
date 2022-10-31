#include "cub3d.h"

int val(t_vector vector, int tmp, int bool)
{
	int i;
	int j;
	char *str;

	i = 0;
	str = "NWSE";
	while(vector.newmap[i++] && i < tmp)
	{
		j = 0;
		while (vector.newmap[i][j])
		{
			if (vector.newmap[i][j] == str[0])
				bool = valid(bool, vector);
			if (vector.newmap[i][j] == str[1])
				bool = valid(bool, vector);
			if (vector.newmap[i][j] == str[2])
				bool = valid(bool, vector);
			if (vector.newmap[i][j] == str[3])
				bool = valid(bool, vector);
			j++;
		}
	}
	return (1);
}

t_vector *sides(t_vector *vector, int tmp)
{
	if (vector == finder(tmp, vector, "N"))
	{
		vector->side = 'N';
		return (vector);
	}
	else if (vector == finder(tmp, vector, "S"))
	{
		vector->side = 'S';
		return (vector);
	}
	else if (vector == finder(tmp, vector, "W"))
	{
		vector->side = 'W';
		return (vector);
	}
	else if (vector == finder(tmp, vector, "E"))
	{
		vector->side = 'E';
		return (vector);
	}
	else
		return (NULL);
}

int ones(t_vector vector, int tmp)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (vector.newmap[i] && i < tmp)
	{
		j = 0;
		while (vector.newmap[0][j])
		{
			if (vector.newmap[0][j] != '1' && vector.newmap[0][j] != ' ')
				error(vector);
			j++;
		}
		j = 0;
		while(vector.newmap[i][j])
		{
			checkssss(vector, i, j);
			j++;
		}
		i++;
	}
	checks(j, i, vector);
	return (1);
}


t_vector map_finder(char **map, t_vector vector)
{
	int i;
	int tmp;
	int tmp2;
	int bool;

	bool = 0;
	i = vector.pos;
	tmp = 0;
	tmp2 = 0;
	while(map[i])
	{
		if (ft_compare(map[i], "1") == 1)
			tmp++;
		i++;
	}
	vector = newmapp(map, i, tmp, tmp2, vector);
	i = 0;
	while(vector.newmap[i] && i < tmp)
	{
		printf("%s\n", vector.newmap[i]);
		i++;
	}
	if (!(&vector == sides(&vector, tmp)))
		error(vector);
	val(vector , tmp, bool);
	ones(vector, tmp);
	return (vector);
}
