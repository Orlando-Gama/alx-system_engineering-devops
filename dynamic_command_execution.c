#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS if successful, otherwise EXIT_FAILURE
 */
int main(void)
{
	#define MAX_INPUT_SIZE 1024
	char input[MAX_INPUT_SIZE];

	printf("Enter the command: ");
	if (fgets(input, sizeof(input), stdin) == NULL)
	{
		perror("fgets");
		exit(EXIT_FAILURE);
	}

	size_t input_length = strlen(input);
	if (input_length > 0 && input[input_length - 1] == '\n')
		input[input_length - 1] = '\0';

	char *command = strtok(input, " ");
	char *arg;
	char *args[32];
	int arg_count = 0;

	while ((arg = strtok(NULL, " ")) != NULL && arg_count < 31)
	{
		args[arg_count++] = arg;
	}
	args[arg_count] = NULL;

	if (execve(command, args, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}

