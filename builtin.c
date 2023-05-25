#include "shell.h"

/**
 * _myexit - this is a function to exit the shell program
 * @info: structure containing potential args
 * Return: exits with a given stat
 */
int _myexit(info_t *info)
{
	int eCheck;

	if (info->argv[1])
	{
		eCheck = _erratoi(info->argv[1]); /* if theres an arg convert to int */
		if (eCheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);/* indicates the given status numb the shell should executes */
	}
info->err_num = -1;
	return (-2);
}
/**
 * _mycd - changes the present dir of a process
 * @info: struct containing potential args
 * Return: Zero all day
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024); /* retrieve cwd */
			if (!s)
				_puts("Unable to get cwd");
			if (!info->argv[1]) /*if no arg*/
			{
				dir = _getenv(info, "HOME=");
				if (!dir)
					chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
				else
					chdir_ret = chdir(dir);
			}
			else if (_strcmp(info->argv[1], "-") == 0)
			{
				if (!_getenv(info, "OLDPWD="))
				{
					_puts(s);
					_putchar('\n');
					return (1);
				}
				_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
				chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
			}
			else
				chdir_ret = chdir(info->argv[1]);
			if (chdir_ret == -1)
			{
				print_error(info, "Can't cd to ");
				_eputs(info->argv[1]), _eputchar('\n');
			}
			else
			{
				_setenv(info, "OLDPWD", _getenv(info, "PWD="));
				_setenv(info, "PWD", getcwd(buffer, 1024));
			}
			return (0);
}
/**
 * _myhelp - change cd of a process
 * @info: ******
 * Return: 0
 */
int _myhelp(info_t *info)
{
	char **array_args;

	array_args = info->argv;
	_puts("Help call works. Function not yet implemented \n");
	if (0)
		_puts(*array_args);
	return (0);
}
/**
 * _myhistory - displays the history list starin at 0
 * @info: ******
 * Return: 0
 */

int _myhistory(info_t *info)
{
	print_list(info->history); /*prints each commands in history list */
	return (0);
}
