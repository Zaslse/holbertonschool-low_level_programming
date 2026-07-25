#include "main.h"
#include <stdlib.h>

/**
 * _isdigit - checks if a string contains a non-digit char
 * @s: string to evaluate
 *
 * Return: 0 if a non-digit is found, 1 otherwise
 */
int _isdigit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * errors - handles errors for main
 */
void errors(void)
{
	char *err = "Error\n";
	int i = 0;

	while (err[i])
	{
		_putchar(err[i]);
		i++;
	}
	exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, i, j, carry, *res, a = 0;

	s1 = argv[1], s2 = argv[2];
	if (argc != 3 || !_isdigit(s1) || !_isdigit(s2))
		errors();
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	res = malloc(sizeof(int) * (len1 + len2 + 1));
	if (!res)
		return (1);
	for (i = 0; i <= len1 + len2; i++)
		res[i] = 0;
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			carry += res[i + j + 1] + ((s1[i] - '0') * (s2[j] - '0'));
			res[i + j + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			res[i] += carry;
	}
	for (i = 0; i < len1 + len2; i++)
	{
		if (res[i])
			a = 1;
		if (a)
			_putchar(res[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(res);
	return (0);
}
