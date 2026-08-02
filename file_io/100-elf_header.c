#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print_mcdv(unsigned char *buf);
void print_osabi_more(unsigned char *buf);
void print_type(unsigned char *buf);
void print_entry(unsigned char *buf);

/**
 * main - displays the information contained in the ELF header
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd, r;
	unsigned char buf[64];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(fd, buf, 64);
	if (r < 16 || buf[0] != 0x7f || buf[1] != 'E' ||
		buf[2] != 'L' || buf[3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		close(fd);
		exit(98);
	}
	printf("ELF Header:\n");
	print_mcdv(buf);
	print_osabi_more(buf);
	print_type(buf);
	print_entry(buf);
	close(fd);
	return (0);
}

/**
 * print_mcdv - prints magic, class, data, and version
 * @buf: buffer containing the ELF header
 */
void print_mcdv(unsigned char *buf)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", buf[i], i == EI_NIDENT - 1 ? '\n' : ' ');

	printf("  Class:                             ");
	if (buf[EI_CLASS] == ELFCLASSNONE)
		printf("none\n");
	else if (buf[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (buf[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", buf[EI_CLASS]);

	printf("  Data:                              ");
	if (buf[EI_DATA] == ELFDATANONE)
		printf("none\n");
	else if (buf[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (buf[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", buf[EI_DATA]);

	printf("  Version:                           %d", buf[EI_VERSION]);
	if (buf[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * print_osabi_more - prints OS/ABI and ABI version
 * @buf: buffer containing the ELF header
 */
void print_osabi_more(unsigned char *buf)
{
	printf("  OS/ABI:                            ");
	if (buf[EI_OSABI] == ELFOSABI_NONE)
		printf("UNIX - System V\n");
	else if (buf[EI_OSABI] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (buf[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (buf[EI_OSABI] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (buf[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (buf[EI_OSABI] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");
	else if (buf[EI_OSABI] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");
	else if (buf[EI_OSABI] == ELFOSABI_TRU64)
		printf("UNIX - TRU64\n");
	else if (buf[EI_OSABI] == ELFOSABI_ARM)
		printf("ARM\n");
	else if (buf[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("Standalone App\n");
	else
		printf("<unknown: %x>\n", buf[EI_OSABI]);

	printf("  ABI Version:                       %d\n", buf[EI_ABIVERSION]);
}

/**
 * print_type - prints type
 * @buf: buffer containing the ELF header
 */
void print_type(unsigned char *buf)
{
	uint16_t type;
	int msb = (buf[EI_DATA] == ELFDATA2MSB);

	type = msb ? (buf[16] << 8) | buf[17] : buf[16] | (buf[17] << 8);

	printf("  Type:                              ");
	if (type == ET_NONE)
		printf("NONE (None)\n");
	else if (type == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (type == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", type);
}

/**
 * print_entry - prints entry point
 * @buf: buffer containing the ELF header
 */
void print_entry(unsigned char *buf)
{
	uint64_t e = 0;
	int msb = (buf[EI_DATA] == ELFDATA2MSB);

	if (buf[EI_CLASS] == ELFCLASS32)
	{
		if (msb)
			e = ((uint32_t)buf[24] << 24) |
				((uint32_t)buf[25] << 16) |
				((uint32_t)buf[26] << 8) | buf[27];
		else
			e = buf[24] | ((uint32_t)buf[25] << 8) |
				((uint32_t)buf[26] << 16) |
				((uint32_t)buf[27] << 24);
		printf("  Entry point address:               0x%x\n", (unsigned int)e);
	}
	else
	{
		if (msb)
			e = ((uint64_t)buf[24] << 56) |
				((uint64_t)buf[25] << 48) |
				((uint64_t)buf[26] << 40) |
				((uint64_t)buf[27] << 32) |
				((uint64_t)buf[28] << 24) |
				((uint64_t)buf[29] << 16) |
				((uint64_t)buf[30] << 8) | buf[31];
		else
			e = buf[24] | ((uint64_t)buf[25] << 8) |
				((uint64_t)buf[26] << 16) |
				((uint64_t)buf[27] << 24) |
				((uint64_t)buf[28] << 32) |
				((uint64_t)buf[29] << 40) |
				((uint64_t)buf[30] << 48) |
				((uint64_t)buf[31] << 56);
		printf("  Entry point address:               0x%lx\n", (unsigned long)e);
	}
}
