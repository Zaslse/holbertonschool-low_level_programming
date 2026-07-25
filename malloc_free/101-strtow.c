#include "main.h"
#include <stdlib.h>

/**
 * util_free - frees a matrix if malloc fails
 * @matrix: array of strings
 * @k: current index
 */
void util_free(char **matrix, int k)
{
	while (k >= 0)
		free(matrix[k--]);
	free(matrix);
}

/**
 * count_words - counts the number of words in a string
 * @s: the string to evaluate
 *
 * Return: number of words
 */
int count_words(char *s)
{
	int flag = 0, c = 0, w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}
	return (w);
}

/**
 * strtow - splits a string into words
 * @str: the string to split
 *
 * Return: pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int i, k = 0, len = 0, words, c = 0, start;

	while (*(str + len))
		len++;
	words = count_words(str);
	if (words == 0)
		return (NULL);

	matrix = malloc((words + 1) * sizeof(char *));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				tmp = malloc((c + 1) * sizeof(char));
				if (tmp == NULL)
				{
					util_free(matrix, k);
					return (NULL);
				}
				while (start < i)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[k++] = tmp - c;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}
	matrix[k] = NULL;
	return (matrix);
}
