/**
 * File: signal_sigaction.c
 * Modified by: Mia Siedentopf
 * Assignment: CPE-2600 Lab 10 - Signals
 */

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * @brief Handler for SIGUSR1 registered with SA_SIGINFO
 * @param sig  the signal number
 * @param info structure with details about the signal (si_pid = sender,
 *             si_value = data sent with sigqueue)
 * @param ctx  unused context pointer
 */
void handle_usr1(int sig, siginfo_t *info, void *ctx)
{
    (void)sig;
    (void)ctx;
    printf("Received SIGUSR1 from process %d\n", (int)info->si_pid);
    printf("Received SIGUSR1 with value %d\n", info->si_value.sival_int);
}

int main(void)
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));          // clear all fields
    sa.sa_sigaction = handle_usr1;       // handler that gets the extra info
    sa.sa_flags = SA_SIGINFO;            // use sa_sigaction, not sa_handler
    sigemptyset(&sa.sa_mask);            // block no extra signals in handler

    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        perror("sigaction");
        return 1;
    }

    printf("My pid is %d, waiting for SIGUSR1...\n", (int)getpid());

    // Wait in an infinite loop; the handler runs when the signal arrives
    while (1)
    {
        pause();
    }

    return 0;
}