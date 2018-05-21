/*
** EPITECH PROJECT, 2021
** tail
** File description:
** Created by mlambotin,
*/

#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "tail.h"

tail_t *create_tail()
{
	tail_t *tail = calloc(1, sizeof(tail_t));

	if (!tail)
		return (NULL);
	tail->tail_mode = LINES;
	tail->nb_elements = 10;
	tail->log_level = DEFAULT;
	return (tail);
}

int count_args(int ac)
{
	int optind_tmp = optind;
	int count = 0;

	while (optind_tmp < ac) {
		++optind_tmp;
		++count;
	}
	return (count);
}

bool run_tail(tail_t *tail, int ac, char **av)
{
	int i = 0;

	if (count_args(ac) > 1)
		tail->log_level = VERBOSE;
	while (optind < ac) {
		if (i != 0 && tail->log_level == VERBOSE)
			printf("\n");
		if (tail->log_level == VERBOSE)
			printf("==> %s <==\n", av[optind]);
		if (!tail_file(tail, av[optind]))
			return (false);
		++optind;
		++i;
	}
	return (true);
}

void delete_tail(tail_t *tail)
{
	if (tail)
		free(tail);
}