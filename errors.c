#include "shell.h"

/**
 * _eputs - prints input string
 * @str: String to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes character e to stderr
 * @e: Character to print
 *
 * Return: 1 on success.
 * -1 is returned on error, and errno is appropriately set.
 */
int _eputchar(char e)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (e == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (e != BUF_FLUSH)
		buf[i++] = e;
	return (1);
}

/**
 * _putfd - writes character e to given fd
 * @e: Character to print
 * @fd: Filedescriptor to write to
 *
 * Return: 1 on success.
 * -1 is returned on error, and errno is appropriately set.
 */
int _putfd(char e, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (e == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (e != BUF_FLUSH)
		buf[i++] = e;
	return (1);
}

/**
 * _putsfd - prints input string
 * @str: String to be printed
 * @fd: Filedescriptor to write to
 *
 * Return: Number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
