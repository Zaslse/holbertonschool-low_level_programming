#include "main.h"

/**
 * infinite_add - adds two numbers represented as strings
 * @n1: first number string
 * @n2: second number string
 * @r: buffer to store the result
 * @size_r: buffer size
 *
 * Return: pointer to the result, or 0 if it cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, sum, carry = 0, i = 0, j, max_len;
	char temp;

	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;

	max_len = len1 > len2 ? len1 : len2;
	if (max_len + 2 > size_r)
		return (0);

	len1--;
	len2--;

	while (len1 >= 0 || len2 >= 0 || carry)
	{
		sum = carry;
		if (len1 >= 0)
			sum += n1[len1--] - '0';
		if (len2 >= 0)
			sum += n2[len2--] - '0';

		carry = sum / 10;
		r[i++] = (sum % 10) + '0';
	}
	r[i] = '\0';

	for (j = 0; j < i / 2; j++)
	{
		temp = r[j];
		r[j] = r[i - 1 - j];
		r[i - 1 - j] = temp;
	}

	return (r);
}
