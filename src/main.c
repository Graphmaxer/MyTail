/*
** EPITECH PROJECT, 2021
** tail
** File description:
** Created by mlambotin,
*/

#include <stdlib.h>
#include <stdio.h>
#include "parsing.h"
#include "tail.h"

int main(int ac, char **av)
{
	tail_t *tail = create_tail();

	setbuf(stdout, NULL);
	if (!tail)
		return (ERROR_VALUE);
	if (!parse_args(tail, ac, av)) {
		delete_tail(tail);
		return (ERROR_VALUE);
	}
	if (!run_tail(tail, ac, av)) {
		delete_tail(tail);
		return (ERROR_VALUE);
	}
	delete_tail(tail);
	return (SUCCESS_VALUE);
}