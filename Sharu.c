#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
int main() {
    pid_t pid;
    // Get and print the process ID
    printf("Parent process ID: %d\n", getpid());
    // Fork a child process
    pid = fork();
    if (pid == -1) {
        // Fork failed
        perror("fork failed");
        exit(1);
    }
    if (pid == 0) {
        // Child process

        // Print the process ID of the child
        printf("Child process ID: %d\n", getpid());

        // Open current directory
        DIR *dir = opendir(".");
        if (dir == NULL) {
            perror("opendir failed");
            exit(1);
        }

        // Read and print the contents of the directory
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            printf("Found file: %s\n", entry->d_name);

            // Check if it is a regular file
            struct stat fileStat;
            if (stat(entry->d_name, &fileStat) == -1) {
                perror("stat failed");
                continue;
            }
            if (S_ISREG(fileStat.st_mode)) {
                printf("%s is a regular file.\n", entry->d_name);
            }
        }

        // Close the directory
        closedir(dir);

        // Exit the child process
        exit(0);
    } else {
        // Parent process

        // Wait for the child to finish
        wait(NULL);

        // Print message from parent
        printf("Child process has finished. Parent process is exiting.\n");

        // Exit the parent process
        exit(0);
    }

    return 0;
}

