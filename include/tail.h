/*
** EPITECH PROJECT, 2021
** tail
** File description:
** Created by mlambotin,
*/

#ifndef TAIL_TAIL_H
#define TAIL_TAIL_H

#include <stdbool.h>

#define SUCCESS_VALUE 0
#define ERROR_VALUE 84

#define BUFFER_SIZE 1024

enum TailMode {
	BYTES,
	LINES
};

enum LogLevel {
	DEFAULT,
	SILENT,
	VERBOSE
};

struct tail_s {
	enum TailMode tail_mode;
	enum LogLevel log_level;
	int nb_elements;
};
typedef struct tail_s tail_t;

tail_t *create_tail();
bool run_tail(tail_t *tail, int ac, char **av);
bool tail_file(tail_t *tail, char *file);
void delete_tail(tail_t *);

#endif //TAIL_TAIL_H
