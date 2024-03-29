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

/* Defines a number of useful constants. */

#ifndef DEFINES_H
# define DEFINES_H

# define TRUE 1
# define FALSE 0
# define FILE_LIMIT 128

// PLAYER DEFAULTS
# define INV_SIZE 6;
# define DEFAULT_HP 25;
# define DEFAULT_DMG 5;

// TEXTURE DEFAULTS
# define TEX_SIZE 64

// WINDOW DEFAULTS
# define WIN_X 1152
# define WIN_Y 1152
# define WINDOW_TITLE "Zoeps's Dungeon"
# define FPS 60

// MAP GEN DEFAULTS
# define MAP_SIZE_X 10
# define MAP_SIZE_Y 10
# define MAX_TUNNELS 365
# define TUNNEL_LENGTH 16

// ASSET LOCATIONS
# define WALL_ASSET_PATH "./assets/walls/"
# define FLOOR_ASSET_PATH "./assets/floors/"

#endif
