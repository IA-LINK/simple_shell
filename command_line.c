#include "shell.h"

/**
 * splitStringIntoWords - Split a string into words
 * @inputString: The input string to be split
 *
 * This function splits a given string into words using space (' ') as a delimiter
 */
void splitStringIntoWords(char *inputString)
{
	char *token;

	token = strtok(inputString, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
}
