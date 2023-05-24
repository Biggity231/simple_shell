#include "shell.h"

/**
 * _eputs - print a input str
 * @str: the string to be printed
 * Return: none
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
 * _eputchar - writes the xtics c to stderr
 * @c: the xtics print
 * Return: If success 1
 * else if error, -1, and errno set apprppriately
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
/**
 * _putfd - writextics c to given fd
 * @c: char to print
 * @fd: The file descriptor
 * Return: 1 for success
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];/*store char before writing */

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - prints an input str
 * @str: the str to be printed
 * @fd: file desc
 * Return: the numb char put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str) /* iterates thru char to write char to spec fd */
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
