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

#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/main.hpp"

game::game(void) : level(DEFAULT_MAP_SIZE_X, DEFAULT_MAP_SIZE_Y) {
	s_width = WIN_X;
	s_height = WIN_Y;
	InitWindow(s_width, s_height, WINDOW_TITLE);
	SetTargetFPS(FPS);
}


int main() {
	int	pos_x, pos_y;
	game reality;
	renderer camera;

	pos_x = pos_y = 10;
	reality.level.print_map();
	reality.level.load_map_textures();
	printf("\n");
	camera.set_render_pos(pos_x, pos_y, &reality.level);
	camera.render(&reality.level);
	while (!WindowShouldClose()) {
		camera.render(&reality.level);
		if (IsKeyReleased(KEY_RIGHT))
			if (!(pos_x + 1 >= reality.level.map_width))
				pos_x += 1;
		if (IsKeyReleased(KEY_LEFT))
			if (!(pos_x - 1 < 0))
				pos_x -= 1;
		if (IsKeyReleased(KEY_DOWN))
			if (!(pos_y + 1 >= reality.level.map_height))
				pos_y += 1;
		if (IsKeyReleased(KEY_UP))
			if (!(pos_y - 1 < 0))
				pos_y -= 1;
		camera.set_render_pos(pos_y, pos_x, &reality.level);
	}
	return (0) ;
}
