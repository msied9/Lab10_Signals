/**
 * File: signal_alarm.c
 * Modified by: Mia Siedentopf
 * Assignment: CPE-2600 Lab 10 - Signals
 * Section: <your section number>
 *
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#define ALARM_SECONDS 5

/**
 * @brief Handler for SIGALRM - prints that the signal was received
 * @param sig the signal number (SIGALRM)
 */
void handle_alarm(int sig)
{
    (void)sig;
    printf("Received SIGALRM: the %d second alarm went off\n", ALARM_SECONDS);
}

int main(void)
{
    // Register the handler BEFORE scheduling the alarm
    signal(SIGALRM, handle_alarm);

    // Ask the OS to send SIGALRM to this process in 5 seconds
    alarm(ALARM_SECONDS);
    printf("Alarm scheduled for %d seconds, waiting...\n", ALARM_SECONDS);

    // pause() suspends the process until any signal is handled
    pause();

    printf("Done.\n");
    return 0;
}