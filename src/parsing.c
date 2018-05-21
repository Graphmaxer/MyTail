/*
** EPITECH PROJECT, 2021
** tail
** File description:
** Created by mlambotin,
*/

#include <stdbool.h>
#include <getopt.h>
#include <stdio.h>
#include "tail.h"
#include "parsing.h"
#include "args.h"

static const struct option LONG_OPTIONS[] = {
	{"bytes", required_argument, 0, 'c'},
	{"lines", required_argument, 0, 'n'},
	{"quiet", no_argument, 0, 'q'},
	{"silent", no_argument, 0, 'q'},
	{"verbose", no_argument, 0, 'v'},
	{0, 0, 0, 0}
};

static const arg_t ARGUMENTS[] = {
	{'c', &handle_bytes_arg},
	{'n', &handle_lines_arg},
	{'q', &handle_quiet_arg},
	{'v', &handle_verbose_arg},
	{0, NULL},
};

bool handle_arg(tail_t *tail, char arg)
{
	for (int i = 0; ARGUMENTS[i].letter != 0; ++i)
		if (ARGUMENTS[i].letter == arg)
			return ((ARGUMENTS[i].fun_ptr)(tail));
	return (false);
}

bool parse_args(tail_t *tail, int ac, char **av)
{
	int c;
	int option_index = 0;

	while (1) {
		c = getopt_long(ac, av, "c:n:qqv", LONG_OPTIONS, &option_index);
		if (c == -1)
			break;
		if (!handle_arg(tail, c))
			return (false);
	}
	return (true);
}