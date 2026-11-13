/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message
 *        (it no longer exits)
 */

/**
 * Modified by: Mia Siedentopf
 * Assignment: CPE-2600 Lab 10 - Signals
 *
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and returns
 * @param sig the number of the signal that was received
 */
void handle_signal(int sig)
{
    (void)sig;  // not needed, we only registered this handler for SIGINT
    printf("Received a signal\n");
    // exit(1) removed: returning lets the program continue where it was
}

int main(void)
{
    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while (1)
    {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}