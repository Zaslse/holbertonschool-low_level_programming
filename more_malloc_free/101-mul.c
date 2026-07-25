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
 * errors - handles errors for main avoiding printf memory leaks
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
	int len1, len2, len, i, carry, digit1, digit2, *result, a = 0;

	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
		errors();
	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
		return (1);
	for (i = 0; i < len; i++)
		result[i] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = argv[1][len1] - '0';
		carry = 0;
		for (len2 = _strlen(argv[2]) - 1; len2 >= 0; len2--)
		{
			digit2 = argv[2][len2] - '0';
			carry += result[len1 + len2 + 1] + (digit1 * digit2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[len1 + len2 + 1] += carry;
	}
	for (i = 0; i < len - 1; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			_putchar(result[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}
