#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../includes/system-killer.h"

/* Check for -1 later... */
int	level_count(char *env[]) {
	char	*pwd;
	int		level_c;

	pwd = getenv("PWD");
	if (!pwd)
		return (-1);
	level_c = 0;
	for (int i = 0; pwd[i]; i++)
		if (pwd[i] == '/')
			level_c++;
	return (level_c);
}

char	**file_name_array(char *dir_name) {
	DIR				*dir;
	struct dirent	*ent;
	int				file_num;
	char			**file_names;

	file_names = malloc(sizeof(char *) * FILE_LIMIT);
	if (!file_names)
		return (NULL);
	dir = opendir(dir_name);
	for (file_num = 0; file_num < FILE_LIMIT; file_num++) {
		ent = readdir(dir);
		file_names[file_num] = strdup(ent->d_name);
		printf("%s\n", file_names[file_num]);
	}
	return (file_names);
}
