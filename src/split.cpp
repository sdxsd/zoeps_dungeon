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

#include <stdlib.h>
#include <string.h>

static int	wordcount(const char *s, char c) {
	int	wc;

	if (!s)
		return (-1);
	wc = 0;
	while (*s) {
		if (*s == c)
			s++;
		if (*s != c && *s != '\0') {
			wc++;
			while (*s != c && *s)
				s++;
		}
	}
	return (wc);
}

static int	gndl(const char *s, char c) {
	int	iterator;

	iterator = 0;
	while (s[iterator] != c && s[iterator])
		iterator++;
	return (iterator);
}

char	**clean_split(char **s_array) {
	while (s_array) {
		if (*s_array)
			free(*s_array);
		s_array += 1;
	}
	free(s_array);
	return (NULL);
}

char	**split(char const *s, char c) {
	char	**s_array;
	size_t	iterator;

	iterator = 0;
	if (!s)
		return (NULL);
	s_array = (char**)malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (!s_array)
		return (NULL);
	while (s_array && iterator < strlen(s)) {
		while (s[iterator] == c && s[iterator] != '\0')
			iterator++;
		if (s[iterator] != c && s[iterator] != '\0')
		{
			*s_array = strndup(&s[iterator], gndl(&s[iterator], c));
			if (!*s_array)
				return (clean_split(s_array - iterator));
			iterator += gndl(&s[iterator], c);
			s_array += 1;
		}
	}
	*s_array = NULL;
	return (s_array - (wordcount(s, c)));
}
