/*
** EPITECH PROJECT, 2021
** tail
** File description:
** Created by mlambotin,
*/

#include <getopt.h>
#include <ctype.h>
#include <stdlib.h>
#include "args.h"

bool handle_nb_elements_arg(tail_t *tail, enum TailMode mode)
{
	int nb;

	if (!optarg)
		return (false);
	for (int i = 0; optarg[i]; ++i)
		if (!isdigit(optarg[i]) && optarg[0] != '-')
			return (false);
	nb = abs(atoi(optarg));
	if (nb < 0)
		nb *= -1;
	tail->tail_mode = mode;
	tail->nb_elements = nb;
	return (true);
}

bool handle_bytes_arg(tail_t *tail)
{
	if (!handle_nb_elements_arg(tail, BYTES))
		return (false);
	return (true);
}

bool handle_lines_arg(tail_t *tail)
{
	if (!handle_nb_elements_arg(tail, LINES))
		return (false);
	return (true);
}

bool handle_quiet_arg(tail_t *tail)
{
	tail->log_level = SILENT;
	return (true);
}

bool handle_verbose_arg(tail_t *tail)
{
	tail->log_level = VERBOSE;
	return (true);
}