#include "main.h"

/**
 * rot13 - encodes a string using rot13
 * @str: the string to encode
 *
 * Return: a pointer to the encoded string
 */
char *rot13(char *str)
{
	int i = 0, j;
	char s1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char s2[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	while (str[i] != '\0')
	{
		for (j = 0; j < 52; j++)
		{
			if (str[i] == s1[j])
			{
				str[i] = s2[j];
				break;
			}
		}
		i++;
	}
	return (str);
}
