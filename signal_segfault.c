/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation
 *        fault, with a handler installed for SIGSEGV
 */

/**
 * Modified by: Mia Siedentopf
 * Assignment: CPE-2600 Lab 10 - Signals
 *
 */

#include <stdio.h>
#include <signal.h>

/**
 * @brief Handler for SIGSEGV - prints a message and returns
 * @param sig the signal number (SIGSEGV)
 */
void handle_segv(int sig)
{
    (void)sig;
    printf("Received a segmentation fault (SIGSEGV)\n");
}

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    // Install the handler for segmentation faults
    signal(SIGSEGV, handle_segv);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}