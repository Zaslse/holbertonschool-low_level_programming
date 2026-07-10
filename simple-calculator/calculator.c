#include <stdio.h>

int read_int(int *value)
{
	int result = scanf("%d", value);
	int c;

	if (result != 1)
	{
		while ((c = getchar()) != '\n' && c != EOF)
			;
		return (0);
	}
	return (1);
}

int main(void)
{
	int choice, a, b;

	printf("Simple Calculator\n");
	while (1)
	{
		printf("1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\n");
		printf("Choice: ");
		if (!read_int(&choice))
		{
			printf("Invalid choice\n");
			continue;
		}
		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}
		if (choice < 1 || choice > 4)
		{
			printf("Invalid choice\n");
			continue;
		}
		printf("A: ");
		while (!read_int(&a))
			printf("Invalid number\nA: ");
		printf("B: ");
		while (!read_int(&b))
			printf("Invalid number\nB: ");
		if (choice == 1)
			printf("Result: %d\n", a + b);
		else if (choice == 2)
			printf("Result: %d\n", a - b);
		else if (choice == 3)
			printf("Result: %d\n", a * b);
		else if (b == 0)
			printf("Error: division by zero\n");
		else
			printf("Result: %g\n", (double)a / b);
	}
	return (0);
}
