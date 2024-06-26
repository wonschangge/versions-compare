#include "compare.h"


char** string_split(const char* in, const char d)
{
	char** result = 0;
	size_t count = 0;
	char* last_delim = 0;
	char delim[2];
	delim[0] = d;
	delim[1] = 0;
	char *s = strdup(in);
	char* tmp = s;
	if (!s)
		return NULL;

	/* Count how many elements will be extracted. */
	while (*tmp) {
		if (d == *tmp) {
			count++;
			last_delim = tmp;
		}
		tmp++;
	}

	/* Add space for trailing token. */
	count += last_delim < (s + strlen(s) - 1);

	/* Add space for terminating null string so caller
	   knows where the list of returned strings ends. */
	count++;

	result = malloc(sizeof(char*) * count);

	if (result) {
		size_t idx  = 0;
		char* token = strtok(s, delim);

		while (token) {
			*(result + idx++) = strdup(token);
			token = strtok(0, delim);
		}
		*(result + idx) = 0;
	}

	free(s);

	return result;
}

void free_string_array(char **nodes)
{
	char **iter;
	if (!nodes)
		return;
	for (iter = nodes; *iter != NULL; iter++)
		free(*iter);
	free(nodes);
}