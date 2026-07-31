#include "main.h"

/**
 * find_strlen - finds the length of a string
 * @s: string
 *
 * Return: length
 */
int find_strlen(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + find_strlen(s + 1));
}

/**
 * check_palindrome - checks if string is a palindrome
 * @s: string
 * @len: length
 * @i: index
 *
 * Return: 1 if palindrome, 0 if not
 */
int check_palindrome(char *s, int len, int i)
{
	if (s[i] == s[len / 2])
		return (1);
	if (s[i] == s[len - i - 1])
		return (check_palindrome(s, len, i + 1));
	return (0);
}

/**
 * is_palindrome - returns 1 if a string is a palindrome and 0 if not
 * @s: string to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = find_strlen(s);

	if (!*s)
		return (1);
	return (check_palindrome(s, len, 0));
}
