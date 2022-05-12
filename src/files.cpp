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

#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../includes/system-killer.hpp"

/* Check for NULL later... */
char	**level_array() {
	char	*pwd;
	char	**lvl_array;

	pwd = getenv("PWD");
	if (!pwd) return (NULL);
	lvl_array = split(pwd, '/');
	if (!lvl_array) return NULL;
	return (lvl_array);
}

char	**file_name_array(char *dir_name) {
	DIR				*dir;
	struct dirent	*ent;
	int				file_num;
	char			**file_names;

	file_names = malloc(sizeof(char *) * FILE_LIMIT);
	if (!file_names) return (NULL);
	dir = opendir(dir_name);
	for (file_num = 0; file_num < FILE_LIMIT; file_num++) {
		ent = readdir(dir);
		if (!ent) break;
		file_names[file_num] = strdup(ent->d_name);
	}
	return (file_names);
}
