#include "shell.h"

/**
 * interactive - to return true if shell is in interactive mode
 * @info: Address of structure
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - to check if char is a delimeter
 * @c: Char to check
 * @delim: Delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - to check for alphabetic char
 * @c: Character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Converts string to integer
 * @e: String to be converted
 * Return: 0 if no number in string, convert number otherwise
 */

int _atoi(char *e)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; e[i] != '\0' && flag != 2; i++)
	{
		if (e[i] == '-')
			sign *= -1;

		if (e[i] >= '0' && e[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (e[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
