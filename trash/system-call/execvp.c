#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    char* command = "ls";
    char* argument_list[] = {"ls", "-l", NULL};

    printf("Before calling execvp()\n");

    // Calling the execvp() system call
    int status_code = execvp(command, argument_list);

    if (status_code == -1) {
        printf("Process did not terminate correctly\n");
        exit(1);
    }

    printf("This line will not be printed if execvp() runs correctly\n");

    return 0;
}
