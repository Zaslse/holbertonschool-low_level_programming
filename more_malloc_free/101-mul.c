#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * _isdigit - checks if a string contains a non-digit char
 * @s: string to evaluate
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
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int l1, l2, len, i, carry, d1, d2, *res, a = 0;

	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}
	s1 = argv[1], s2 = argv[2];
	l1 = _strlen(s1);
	l2 = _strlen(s2);
	len = l1 + l2 + 1;
	res = malloc(sizeof(int) * len);
	if (!res)
		return (1);
	for (i = 0; i <= l1 + l2; i++)
		res[i] = 0;
	for (l1 = l1 - 1; l1 >= 0; l1--)
	{
		d1 = s1[l1] - '0';
		carry = 0;
		for (l2 = _strlen(s2) - 1; l2 >= 0; l2--)
		{
			d2 = s2[l2] - '0';
			carry += res[l1 + l2 + 1] + (d1 * d2);
			res[l1 + l2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			res[l1 + l2 + 1] += carry;
	}
	for (i = 0; i < len - 1; i++)
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
