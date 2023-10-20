#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


#define MAX_INPUT_LEN 1024
extern char **environ;
void _prompt_display(void);
void exit_function(void);
char *my_strdup(const char *str);
char *my_strcat(char *dest, char *src);
int my_strcmp(const char *str1, const char *str2);
size_t my_strlen(const char *str);
int is_whitespace(char c);
char *_strtrim(char *c);
char *_getpath(const char *command);
char *my_strcpy(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *my_getenv(const char *name);
int _execommand(char *command_with_args);
void _execute_childprocess(char *command, char *args[]);
void print_env(void);
char *custom_getline(void);
void *_re_alloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_mem_set(char *s, char b, unsigned int n);
void _ffree(char **pp);
#endif /* SHELL_H */
