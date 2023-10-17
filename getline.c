#include "shell.h"

#define MAX_LINE_LENGTH 100

static char input_buffer[MAX_LINE_LENGTH];
static size_t buffer_position = 0;
static size_t buffer_size = 0;

/**
 * custom_getline - Read input from standard input and return a line.
 *
 * This function reads input from standard input in chunks into a static buffer,
 * minimizing calls to the read system call. It detects newline characters and returns lines accordingly.
 *
 * Return: A dynamically allocated string containing the line, or NULL if there's no more input or an error occurs.
 */
char *custom_getline(void)
{
	char *line = NULL;
	size_t line_length = 0;
	size_t i;
	size_t buffer_copy_length;
	char *buffer_copy;

	while (1)
	{
		if (buffer_position >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, input_buffer, sizeof(input_buffer));
			if (buffer_size <= 0)
			{
				if (line != NULL)
				{
					free(line);
					return (NULL);
				}
				return (NULL);
			}
			buffer_position = 0;
		}

		for (i = buffer_position; i < buffer_size; i++)
		{
			if (input_buffer[i] == '\n')
			{
				size_t line_copy_length = i - buffer_position;
				char *line_copy = (char *)malloc(line_length + line_copy_length + 1);

				if (line == NULL)
				{
					line = line_copy;
				}
				else
				{
					memcpy(line_copy, line, line_length);
					free(line);
					line = line_copy;
				}
				memcpy(line + line_length, input_buffer + buffer_position, line_copy_length);
				line_length += line_copy_length;
				line[line_length] = '\0';
				buffer_position = i + 1;
				return (line);
			}
		}
		buffer_copy_length = buffer_size - buffer_position;
		buffer_copy = (char *)malloc(line_length + buffer_copy_length + 1);

		if (line == NULL)
		{
			line = buffer_copy;
		}
		else
		{
			memcpy(buffer_copy, line, line_length);
			free(line);
			line = buffer_copy;
		}
		memcpy(line + line_length, input_buffer + buffer_position, buffer_copy_length);
		line_length += buffer_copy_length;
		line[line_length] = '\0';
		buffer_position = buffer_size;
	}
}
