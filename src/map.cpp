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
#include <dirent.h>
#include <vector>
#include <time.h>
#include "../includes/main.hpp"


int	Map::generate_style(void) {
	std::vector<struct dirent *>	asset_files;
	struct dirent					*direc_entry;
	DIR								*direc_pointer;
	int								file_c;

	direc_pointer = opendir(FLOOR_ASSET_PATH);
	if (!direc_pointer)
		return (FALSE);
	while (TRUE) {
		direc_entry = readdir(direc_pointer);
		if (direc_entry) {
			file_c++;
			asset_files.push_back(direc_entry);
		}
		else
			break;
	}
	closedir(direc_pointer);
	return (TRUE);
}

Map::Map(int x, int y) {
	width = x;
	height = y;

	map_data = (char**)calloc(sizeof(char*), height);
	if (!map_data)
		throw printf("Malloc failure\n");
	for (int i = 0; i <= height; i++)
		if (!(map_data[i] = (char*)calloc(sizeof(char), width)))
			throw printf("Malloc failure\n");
	for (int i = 0; i <= height; i++)
		for (int z = 0; z <= width; z++)
			map_data[i][z] = '#';
	img_wall = LoadImage("assets/wll.png");
	img_floor = LoadImage("assets/flr.png");
	map_generate();
}

Map::~Map(void) {
	for (int i = 0; i < height; i++)
		free(map_data[i]);
	UnloadImage(img_floor);
	UnloadImage(img_wall);
	printf("Map freed\n");
}

int Map::draw_to_image(Image dst, Image src, int x, int y) {
	Rectangle	dst_rec;
	Rectangle	src_rec;

	dst_rec.x = (float)x;
	dst_rec.y = (float)y;
	dst_rec.height = (float)src.height;
	dst_rec.width = (float)src.width;
	src_rec.x = 0;
	src_rec.y = 0;
	src_rec.height = (float)src.height;
	src_rec.width = (float)src.width;
	ImageDraw(&dst, src, src_rec, dst_rec, WHITE);
	return (TRUE);
}

Image Map::gen_image(void) {
	Image	img;

	img = GenImageColor(width * TEX_SIZE, height * TEX_SIZE, WHITE);
	for (int y = 0; y <= height; y++) {
		for (int x = 0; x <= width; x++) {
			if (map_data[y][x] == '.')
				draw_to_image(img, img_floor, x * TEX_SIZE,  y * TEX_SIZE);
			else if (map_data[y][x] == '#')
				draw_to_image(img, img_wall, x * TEX_SIZE, y * TEX_SIZE);
		}
	}
	return (img);
}

int	get_seed(void) {
	int	fd;
	int	*num;
	int	ret;

	num = (int*)malloc(sizeof(int));
	if (!num)
		return (-1);
	fd = open("/dev/urandom", O_RDONLY);
	read(fd, num, sizeof(int));
	ret = *num;
	free(num);
	close(fd);
	return (ret);
}

void Map::border_walls(void) {
	int	iterator_y = 0;
	int	iterator_x = 0;

	while (iterator_y++ < height)
	{
		map_data[iterator_y][width] = '#';
		map_data[iterator_y][0] = '#';
	}
	while (iterator_x++ < width) {
		map_data[height - 1][iterator_x] = '#';
		map_data[0][iterator_x] = '#';
	}
}

void Map::print_map(void) {
	for (int i = 0; i < height; i++)
		printf("%s\n", map_data[i]);
}

char **Map::map_generate(void) {
	int	g_tunnels = 0;
	int	start_x, start_y, x, y;
	int	length, direction, last_direction;

	last_direction = -1;
	start_x = GetRandomValue(0, width);
	start_y = GetRandomValue(0, height);
	x = start_x;
	y = start_y;
	while (g_tunnels < MAX_TUNNELS - 30) {
		SetRandomSeed(get_seed());
		length = GetRandomValue(4, TUNNEL_LENGTH);
		direction = GetRandomValue(0,3);
		if (last_direction == 0 || last_direction == 1)
				direction = GetRandomValue(2,3);
		else if (last_direction == 2 || last_direction == 3)
				direction = GetRandomValue(0,1);
		last_direction = direction;
		switch (direction) {
			case 0:
				for (int i = 0; y > 0 && i < length; i++)
					map_data[y--][x] = '.';
			case 1:
				for (int i = 0; y < height && i < length; i++)
					map_data[y++][x] = '.';
			case 2:
				for (int i = 0; x > 0 && i < length; i++)
					map_data[y][x--] = '.';
			case 3:
				for (int i = 0; x < width && i < length; i++)
					map_data[y][x++] = '.';
		}
		if (x == width || y == height) {
			x = start_x;
			y = start_y;
		}
		g_tunnels++;
	}
	border_walls();
	return (map_data);
}
