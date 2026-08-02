#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void check_io(int stat, int fd, char *filename, char mode);

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, r, w;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	check_io(fd_from, -1, argv[1], 'O');

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	check_io(fd_to, -1, argv[2], 'W');

	while ((r = read(fd_from, buf, 1024)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w != r)
			check_io(-1, -1, argv[2], 'W');
	}
	if (r == -1)
		check_io(-1, -1, argv[1], 'O');

	check_io(close(fd_from), fd_from, NULL, 'C');
	check_io(close(fd_to), fd_to, NULL, 'C');

	return (0);
}

/**
 * check_io - checks if a file can be opened, written or closed
 * @stat: return value of the operation to evaluate
 * @fd: file descriptor
 * @filename: name of the file
 * @mode: operation mode (O, W, C)
 */
void check_io(int stat, int fd, char *filename, char mode)
{
	if (mode == 'C' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
	else if (mode == 'O' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	else if (mode == 'W' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}
