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
	int l1, l2, len, i, j, carry, d1, d2, *res, a = 0;

	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
		errors();
	l1 = _strlen(argv[1]);
	l2 = _strlen(argv[2]);
	len = l1 + l2;
	res = malloc(sizeof(int) * len);
	if (!res)
		return (1);
	for (i = 0; i < len; i++)
		res[i] = 0;
	for (i = l1 - 1; i >= 0; i--)
	{
		d1 = argv[1][i] - '0';
		carry = 0;
		for (j = l2 - 1; j >= 0; j--)
		{
			d2 = argv[2][j] - '0';
			carry += res[i + j + 1] + (d1 * d2);
			res[i + j + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			res[i + j + 1] += carry;
	}
	for (i = 0; i < len - 1; i++)
	{
		if (res[i])
			a = 1;
		if (a)
			_putchar(res[i] + '0');
	}
	_putchar(res[len - 1] + '0');
	_putchar('\n');
	free(res);
	return (0);
}
