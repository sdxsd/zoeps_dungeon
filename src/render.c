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
#include "../includes/system-killer.h"

/* int	rndr_loop() */
/* { */

/* } */

int	algemeen_init(game_data *game) {
	InitWindow(WIN_X, WIN_Y, "System Killer!");
	load_textures(game);
	game->textures.plyr = LoadTextureFromImage(game->images.plyr);
	game->textures.flr = LoadTextureFromImage(game->images.flr);
	game->textures.wll = LoadTextureFromImage(game->images.wll);
	while(!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(BLACK);
			DrawTexture(game->textures.plyr, WIN_X / 2, WIN_Y / 2, WHITE);
			DrawTexture(game->textures.wll, 0, 0, WHITE);
			DrawTexture(game->textures.flr, WIN_X - 128, WIN_Y - 128, WHITE);
		EndDrawing();
	}
	return (TRUE);
}
