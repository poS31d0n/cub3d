#include "inc/cub3d.h"

void	freetmp(int h, char *tmp, t_vector vector, char ** map)
{
	if (h < 2)
	{
		free(tmp);
		errormap(vector, map);
	}
}

void booling(int bool, int i, int j, char *str, t_vector vector)
{
	if (vector.newmap[i][j] == str[0])
		bool = valid(bool, vector);
	if (vector.newmap[i][j] == str[1])
		bool = valid(bool, vector);
	if (vector.newmap[i][j] == str[2])
		bool = valid(bool, vector);
	if (vector.newmap[i][j] == str[3])
		bool = valid(bool, vector);
}

void checks(int j, int i, t_vector vector)
{
	j = 0;
	i = i - 1;
	while (vector.newmap[i][j])
	{
		if (vector.newmap[i][j] != '1' && vector.newmap[i][j] != ' ')
				error(vector);
		j++;
	}
}

void checkssss(t_vector vector, int i, int j)
{
	if (vector.newmap[i][0] != '1' && vector.newmap[i][0] != ' ')
		error(vector);
	if (vector.newmap[i][j + 1] == '\n' || vector.newmap[i][j + 1] == '\0')
		{
			if (vector.newmap[i][j] != '1')
			error(vector);
		}
}
