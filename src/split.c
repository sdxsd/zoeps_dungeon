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
	s_array = malloc(sizeof(char *) * (wordcount(s, c) + 1));
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
