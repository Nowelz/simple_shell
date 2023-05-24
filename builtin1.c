#include "shell.h"

/**
 * _myhistory - Displays history list, one command by line, headed
 *              with line numbers, starting at 0.
 * @info: structure that contains potential arguments. used to maintain
 *        constant function prototype.
 *  Return: always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: Parameter structure
 * @str: String alias
 *
 * Return: always 0 when successful, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *d, c;
	int ret;

	d = _strchr(str, '=');
	if (!d)
		return (1);
	c = *d;
	*d = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*d = c;
	return (ret);
}

/**
 * set_alias - Sets alias to string
 * @info: Parameter structure
 * @str: String alias
 *
 * Return: always 0 when successful, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *d;

	d = _strchr(str, '=');
	if (!d)
		return (1);
	if (!*++d)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - Prints alias string
 * @node: alias node
 *
 * Return: always 0 when successful, 1 on error
 */
int print_alias(list_t *node)
{
	char *d = NULL, *a = NULL;

	if (node)
	{
		d = _strchr(node->str, '=');
		for (a = node->str; a <= d; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(d + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics alias builtin (man alias)
 * @info: structure that contains potential arguments. used to maintain
 *          constant function prototype.
 *  Return: always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *d = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		d = _strchr(info->argv[i], '=');
		if (d)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
