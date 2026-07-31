#include "main.h"

/**
 * find_sqrt - finds the natural square root of an input number
 * @num: number to find the square root of
 * @root: the root to be tested
 *
 * Return: natural square root, or -1 if none exists
 */
int find_sqrt(int num, int root)
{
	if ((root * root) == num)
		return (root);
	if (root == num / 2)
		return (-1);
	return (find_sqrt(num, root + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to calculate the square root of
 *
 * Return: natural square root, or -1 if not natural
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 1)
		return (1);
	return (find_sqrt(n, 0));
}
