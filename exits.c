#include "shell.h"

/**
 **_strncpy - copies string
 *@dest: Destination string to be copied to
 *@src: Source string
 *@n: Amount of characters to be copied
 *Return: Concatenated string
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
 **_strncat - to concatenate two strings
 *@dest: First string
 *@src: Second string
 *@n: Amount of bytes to be maximally used
 *Return: Concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, b;
	char *s = dest;

	i = 0;
	b = 0;
	while (dest[i] != '\0')
		i++;
	while (src[b] != '\0' && b < n)
	{
		dest[i] = src[b];
		i++;
		b++;
	}
	if (b < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - to locates a character in a string
 *@s: String to be parsed
 *@c: Character to look for
 *Return: (s) a pointer to memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
