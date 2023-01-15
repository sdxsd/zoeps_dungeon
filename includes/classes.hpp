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

#ifndef CLASSES_H
# define CLASSES_H
# include "defines.hpp"
# include <raylib.h>

class Inventory;
class Player;
class Entity;
class Item;
class Game;
class Map;

class Entity {
	private:
		Texture2D	tex;
		char		*name;
		short		lvl;
		short		hp;
		short 		dmg;
	public:
		int			pos_x;
		int			pos_y;

		Entity (void);
		int entity_load_texture(char *path);
		int	draw_entity(int x, int y);
};

class Item {
	private:
		void		(*effect_Player)(Player *plyr);
		Texture2D	item_texture;
	public:
		char	**description;
		char	**e_description;

		char **gen_description(void);
		Item (void);
};

class Inventory {
	private:
		Item	items[6];
		int		items_count;
	public:
		Inventory (void);
		void add_item(Item to_add);
		void remove_item(int id);
		Item use_item(int id);
};

class Player : Entity {
	// private:
		// Inventory	inv;
	public:
		Vector2		pos_vec;

		Player(Game *game);
};

class Map {
	private:
		char	**map_data;
		int		height;
		int		width;
		Image	img_floor;
		Image	img_wall;
	public:
		char	**map_generate(void);
		void	print_map(void);
		void	border_walls(void);
		int		draw_to_image(Image dst, Image src, int x, int y);
		Image	gen_image(void);
		Map(int x, int y);
		~Map(void);
};

class Game {
	public:
		Texture2D	lvl_texture;
		Camera2D	plyr_cam;
		Image		*lvl_image;
		Player		*player;
		int			w_height;
		int			w_width;
		Map			*level;

		Game(void);
		~Game(void);
};

#endif // CLASSES_H
