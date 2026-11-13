/**
 * File: send_signal.c
 * Modified by: Mia Siedentopf
 * Assignment: CPE-2600 Lab 10 - Signals
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    // Convert the command line argument to a pid, checking for bad input
    char *end;
    long value = strtol(argv[1], &end, 10);
    if (*end != '\0' || end == argv[1] || value <= 0)
    {
        fprintf(stderr, "Error: '%s' is not a valid pid\n", argv[1]);
        return 1;
    }
    pid_t pid = (pid_t)value;

    // Seed the generator so each run gives a different number
    srand((unsigned int)time(NULL));
    int number = rand();
    printf("Sending number %d to process %d\n", number, (int)pid);

    // Data is carried in a union sigval; we use its integer member
    union sigval data;
    data.sival_int = number;

    if (sigqueue(pid, SIGUSR1, data) == -1)
    {
        perror("sigqueue");
        return 1;
    }

    return 0;
}