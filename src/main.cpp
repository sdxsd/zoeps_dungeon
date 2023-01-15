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

Game::~Game(void) {
	delete level;
	CloseWindow();
}

Game::Game(void) {
	w_width = WIN_X;
	w_height = WIN_Y;
	InitWindow(w_width, w_height, WINDOW_TITLE);
	SetTargetFPS(FPS);
	level = new Map(MAP_SIZE_X, MAP_SIZE_Y);
	*lvl_image = level->gen_image();
}

int main() {
	Game		reality;
	Player		plyr(&reality);

	*reality.lvl_image = reality.level->gen_image();
	reality.lvl_texture = LoadTextureFromImage(*reality.lvl_image);
	reality.plyr_cam.offset = (Vector2) {(float)reality.w_width/2.0f, (float)reality.w_height/2.0f};
	reality.plyr_cam.target = plyr.pos_vec;
	reality.plyr_cam.rotation = 0.0f;
	reality.plyr_cam.zoom = 1.0f;
	while (!WindowShouldClose()) // Ran every frame.
	{
		BeginDrawing();
		BeginMode2D(reality.plyr_cam);
		DrawTexture(reality.lvl_texture, 0, 0, WHITE);
		update(&plyr, &reality.plyr_cam);
		EndMode2D();
		EndDrawing();
	}
	return (0);
}
