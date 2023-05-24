#include "shell.h"

/**
 * unset_alias - setting alias to str
 * @info: params struct
 * @str: the str alias
 *
 * Return: 0 if succeed else 1
 */
int unset_alias(info_t *info, char *str)
{
	char *p;
	char c;

	int reTurn;

		p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;

	reTurn = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (reTurn);
}

/**
 * set_alias - setting alias to str
 * @info: params struct
 * @str: the str alias
 *
 * Return: 0 on success, 1 if error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * replace_alias - replace an aliases int the tokenized str
 * @info: the params struct
 * Return: 1 if replacedotherwise
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *n;
	char *p;

	for (i = 0; i < 10; i++)
	{
		n = node_starts_with(info->alias, info->argv[0], '=');
		if (!n)
			return (0);
		free(info->argv[0]);
		p = _strchr(n->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0)
		info->argv[0] = p;
	}
	return (1);
}
/**
 * print_alias - print alias str
 * @n: alias node
 * Return: 0 or 1 error
 */
int print_alias(list_t *n)
{
	char *p = NULL;
	char *a = NULL;

	if (n)
	{
		p = _strchr(n->str, '=');
		for (a = n->str; a <= p; a++)
			_putchar(*a);

			_putchar('\'');
			_puts(p + 1);
			_puts("'\n");
			return (0);
	}
	return (1);
}

/**
 * _myalias - copying the builtin alias
 * @info: structure containing potential args
 * Return: 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *n = NULL;

	if (info->argc == 1)
	{
		n = info->alias;
		while (n)
		{
			print_alias(n);
			n = n->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i], i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}
	return (0);
}
