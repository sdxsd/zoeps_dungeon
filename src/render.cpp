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
#include "../includes/main.hpp"

/* int	rndr_loop() */
/* { */

/* } */

int	render_map(Texture2D *flr, char **map, int x, int y) {
	for (int i = 0; i < y; i++) {
		for (int z = 0; z < x; z++) {
			BeginDrawing();
			switch (map[i][z]) {
			case '0':
				DrawTexture(*flr, z * TEX_SIZE, i * TEX_SIZE, WHITE);
			case '1':
				DrawTexture(*flr, z * TEX_SIZE, i * TEX_SIZE, WHITE);
			default: return (FALSE);
			}
			EndDrawing();
		}
	}
	return (TRUE);
}

int	algemeen_init(game_data *game) {
	InitWindow(WIN_X, WIN_Y, "System Killer!");
	load_textures(game);
	game->textures.plyr = LoadTextureFromImage(game->images.plyr);
	game->textures.flr = LoadTextureFromImage(game->images.flr);
	game->textures.wll = LoadTextureFromImage(game->images.wll);
	BeginDrawing();
		ClearBackground(BLACK);
		render_map(&game->textures.flr, game->map, DEFAULT_MAP_SIZE_X, DEFAULT_MAP_SIZE_Y);
	EndDrawing();
	while (!WindowShouldClose())
		;
	return (TRUE);
}