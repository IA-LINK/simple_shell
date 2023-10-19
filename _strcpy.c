/**
 * *my_strcpy - copies the string pointed to by src
 * including the terminating null byte \0
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
char *my_strcpy(char *dest, char *src)
{
	int length, j;

	length = 0;

	while (src[length] != '\0')
	{
		length++;
	}

	for (j = 0; j < length; j++)
	{
		dest[j] = src[j];
	}
	dest[j] = '\0';

	return (dest);
}
