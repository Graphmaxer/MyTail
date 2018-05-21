/*
** EPITECH PROJECT, 2021
** tail
** File description:
** Created by mlambotin,
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "tail.h"

bool tail_bytes(tail_t *tail, int fd)
{
	char buffer[tail->nb_elements];
	ssize_t len;

	lseek(fd, -tail->nb_elements, SEEK_END);
	len = read(fd, buffer, tail->nb_elements);
	if (len == -1)
		return (false);
	if (write(1, buffer, len) == -1)
		return (false);
	return (true);
}

int read_lines(tail_t *tail, int fd, int *newline_count, int i)
{
	__off_t len;
	ssize_t readed;
	char buffer[1];

	len = lseek(fd, -1, SEEK_CUR);
	if (len == -1)
		return (1);
	readed = read(fd, buffer, 1);
	if (readed == -1)
		return (-1);
	if (buffer[0] == '\n' && i == 0)
		++tail->nb_elements;
	if (buffer[0] == '\n')
		++(*newline_count);
	if ((*newline_count) != tail->nb_elements &&
		lseek(fd, -1, SEEK_CUR) == -1)
		return (-1);
	return (0);
}

bool tail_lines(tail_t *tail, int fd)
{
	ssize_t readed;
	int i = 0;
	int newline_count = 0;
	char buffer[BUFFER_SIZE];

	if (lseek(fd, 0, SEEK_END) == -1)
		return (false);
	while (newline_count != tail->nb_elements) {
		if (read_lines(tail, fd, &newline_count, i) == 1)
			break;
		++i;
	}
	while ((readed = read(fd, buffer, BUFFER_SIZE)) > 0) {
		if (readed == -1)
			return (false);
		write(1, buffer, readed);
	}
	return (true);
}

bool tail_file(tail_t *tail, char *file)
{
	int fd = open(file, O_RDONLY);
	bool ret = true;

	if (fd == -1)
		return (false);
	if (tail->tail_mode == BYTES)
		ret = tail_bytes(tail, fd);
	if (tail->tail_mode == LINES)
		ret = tail_lines(tail, fd);
	close(fd);
	return (ret);
}