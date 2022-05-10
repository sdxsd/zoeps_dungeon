/*
THIS FILE IS LICENSED UNDER THE GNU GPLv3

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>

The definition of Free Software is as follows:
				- The freedom to run the program, for any purpose.
				- The freedom to study how the program works, and adapt it to your needs.
				- The freedom to redistribute copies so you can help your neighbor.
				- The freedom to improve the program, and release
				your improvements to the public, so that the whole community benefits.

A program is free software if users have all of these freedoms.
*/

#include <stdlib.h>
#include <raylib.h>
#include <stdio.h>
#include <time.h>
#include "../includes/system-killer.h"

char	**init_map(int x, int y) {
	char	**map;

	map = calloc(sizeof(char*) * y, 1);
	if (!map) return (NULL);
	for (int i = 0; i <= y; i++)
		if (!(map[i] = calloc(sizeof(char), x)))
			return (NULL);
	for (int i = 0; i <= y; i++)
		for (int z = 0; z <= x; z++)
			map[i][z] = '1';
	return (map);
}

/* Drunkard walk algorithm. */
char	**map_generate(char	**map, int x, int y) {
	int	point_x;
	int	point_y;
	int	iterations;
	int	i;

	iterations = 0;
	SetRandomSeed(time(NULL));
	point_x = GetRandomValue(0, x);
	point_y = GetRandomValue(0, y);
	map[point_y][point_x] = '0';
	while(iterations < MAP_GEN_ITERATIONS * 5) {
		switch (i = GetRandomValue(1,4)) {
			case 1:
				point_x++;
			case 2:
				point_y++;
			case 3:
				point_x--;
			case 4:
				point_y--;
		}
		if (point_x > x || point_y > y
			|| point_x < 0 || point_y < 0)
			;
		else
			map[point_y][point_x] = '0';
		iterations++;
	}
	for (int i = 0; i <= y; i++)
		printf("%s\n", map[i]);
	return (map);
}
