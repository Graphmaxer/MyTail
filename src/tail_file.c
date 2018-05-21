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

bool tail_lines(tail_t *tail, int fd)
{
	__off_t len;
	ssize_t readed;
	int newline_count = 0;
	char buffer[BUFFER_SIZE];

	if (lseek(fd, 0, SEEK_END) == -1)
		return (false);
	while (newline_count != tail->nb_elements) {
		len = lseek(fd, -1, SEEK_CUR);
		if (len == -1)
			break;
		readed = read(fd, buffer, 1);
		if (readed == -1)
			return (false);
		if (buffer[0] == '\n')
			++newline_count;
		if (newline_count != tail->nb_elements &&
			lseek(fd, -1, SEEK_CUR) == -1)
			return (false);
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