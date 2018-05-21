/*
** EPITECH PROJECT, 2021
** tail
** File description:
** Created by mlambotin,
*/

#ifndef TAIL_ARGS_H
#define TAIL_ARGS_H

#include <stdbool.h>
#include "tail.h"

bool handle_bytes_arg(tail_t *tail);
bool handle_lines_arg(tail_t *tail);
bool handle_quiet_arg(tail_t *tail);
bool handle_verbose_arg(tail_t *tail);

#endif //TAIL_ARGS_H
