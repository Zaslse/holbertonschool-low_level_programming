#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates a random valid password for 101-crackme
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int sum = 0;
	int n;

	srand(time(NULL));

	while (sum < 2646)
	{
		n = (rand() % 10) + 70;
		printf("%c", n);
		sum += n;
	}

	printf("%c", 2772 - sum);

	return (0);
}
