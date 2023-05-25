#include "shell.h"

/**
 * *_strncpy- copies a str
 * @dest: the dest str to be copied
 * @src: the src string
 * @n: the amount of char
 * Return: the concat str
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}
/**
 * *_strncat - concat two str
 * @dest: the first str
 * @src: the sec str
 * @n: the amount of bytes to be maximally used
 * Return: the concat str
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}
/**
 * *_strchr - locates a char in a str
 * @s: the str to be parsed
 * @c: the char
 * Return: (s) a pointer to memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
	return (NULL);
}

