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

#include <cstdlib>
#include <raylib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include "../includes/main.hpp"

map::map(int x, int y) {
	map_width = x;
	map_height = y;
	map_data = init_map();
	map_generate();
}

char	**map::init_map(void) {
	char	**map;

	map = (char**)calloc(sizeof(char*) * map_height, 1);
	if (!map) return (NULL);
	for (int i = 0; i <= map_height; i++)
		if (!(map[i] = (char*)calloc(sizeof(char), map_width)))
			return (NULL);
	for (int i = 0; i <= map_height; i++)
		for (int z = 0; z <= map_width; z++)
			map[i][z] = '1';
	return (map);
}

void	map::print_map(void) {
	for (int i = 0; i < map_height; i++)
		printf("%s\n", map_data[i]);
}

char	**map::map_generate(void) {
	int	g_tunnels = 0;
	int	start_x, start_y;
	int	length, direction, last_direction;

	last_direction = -1;
	start_x = GetRandomValue(0,map_width);
	start_y = GetRandomValue(0,map_height);
	SetRandomSeed(time(NULL));
	while (g_tunnels < MAX_TUNNELS) {
		length = GetRandomValue(0, length);
		direction = GetRandomValue(0,3);
		while (direction == last_direction)
			direction = GetRandomValue(0,3);
		last_direction = direction;
		switch (direction) {
			case 0:
				for (int i = 0; start_y > 0 && i < length; i++)
					map_data[start_y--][start_x] = '0';
			case 1:
				for (int i = 0; start_y < map_height && i < length; i++)
					map_data[start_y++][start_x] = '0';
			case 2:
				for (int i = 0; start_x > 0 && i < length; i++)
					map_data[start_y][start_x--] = '0';
			case 3:
				for (int i = 0; start_x < map_width && i < length; i++)
					map_data[start_y][start_x++] = '0';
		}
		g_tunnels++;
	}
	return (map_data);
}
