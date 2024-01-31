#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Example command and arguments
    char *command = "/bin/ps";
    char *args[] = { "ps", "aux", NULL };

    // Execute the command using execve
    if (execve(command, args, NULL) == -1) {
        perror("execve");  // Print an error message if execve fails
        exit(EXIT_FAILURE);
    }

    // This part will only be reached if execve fails
    return EXIT_FAILURE;
}
