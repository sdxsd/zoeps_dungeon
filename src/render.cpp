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

#include "../includes/main.hpp"
#include <stdio.h>

static int draw_to_image(Image dst, Image src, int x, int y) {
	Rectangle	dst_rec;
	Rectangle	src_rec;

	dst_rec.x = 0;
	dst_rec.y = 0;
	dst_rec.height = (float)dst.height;
	dst_rec.width = (float)dst.width;
	src_rec.x = (float)x;
	src_rec.y = (float)y;
	src_rec.height = (float)src.height;
	src_rec.width = (float)src.width;
	ImageDraw(&dst, src, src_rec, dst_rec, WHITE);
}

Image renderer::gen_image(map *map, int width, int height) {
	Image	img;

	img = GenImageColor(WIN_X, WIN_Y, WHITE);
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++) {
			if (map->map_data[y][x] == '.')
				draw_to_image(img, map->img_floor, x * TEX_SIZE, y * TEX_SIZE);
			else if (map->map_data[y][x] == '#')
				draw_to_image(img, map->img_wall, x * TEX_SIZE, y * TEX_SIZE);
		}
	return (img);
}

renderer::renderer(void) {
	camera_pos_x = 0;
	camera_pos_y = 0;
	render_distance = RENDER_DISTANCE;
}

int	renderer::render(map *map) {
	int	render_box_x = camera_pos_x - render_distance / 2;
	int	render_box_y = camera_pos_y - render_distance / 2;
	while (render_box_x < 0)
		render_box_x++;
	while (render_box_y < 0)
		render_box_y++;
	while (render_box_x > map->map_width)
		render_box_x--;
	while (render_box_y > map->map_height)
		render_box_y--;
	for (int i = 0; i < render_distance; i++) {
		for (int x = 0; x < render_distance; x++) {
			if (map->map_data[render_box_x + i][render_box_y + x] == '.')
				DrawTexture(map->tex_floor, x * TEX_SIZE, i * TEX_SIZE, BLUE);
			else if (map->map_data[render_box_x + i][render_box_y + x] == '#')
				DrawTexture(map->tex_wall, x * TEX_SIZE, i * TEX_SIZE, RED);
		}
	}
	return (TRUE);
}

int renderer::set_render_pos(int x, int y, map *map) {
	if (x > map->map_width - render_distance || x < 0 ||
		y > map->map_height - render_distance || y < 0)
		return (FALSE);
	else {
		camera_pos_x = x;
		camera_pos_y = y;
		return (TRUE);
	}
}
