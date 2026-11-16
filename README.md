# Lab 10: Signals

CPE-2600 Systems Programming, Fall 2026

Name: Mia Siedentopf

## Build

- Build everything: `make`
- Remove built files: `make clean`

## Programs

1. `signal_handler`: handles SIGINT. The handler prints a message and does
   not exit, so the program keeps running. Stop it with `kill -9`.
2. `signal_alarm`: sets an alarm for 5 seconds. When SIGALRM arrives, the
   handler prints a message.
3. `signal_segfault`: handles SIGSEGV. The handler returns, so the faulting
   line runs again and the message repeats until CTRL+C.
4. `signal_sigaction`: uses `sigaction` to handle SIGUSR1 and prints the
   process id of the sender.
5. `recv_signal`: uses `sigaction` to handle SIGUSR1 and prints the number
   that was sent with the signal.
6. `send_signal`: sends SIGUSR1 and a random number to a process using
   `sigqueue`.

## How to run recv_signal and send_signal

1. In one terminal, run `./recv_signal`. It prints its process id.
2. In a second terminal, run `./send_signal <pid>` using that process id.
3. `send_signal` prints the number it sends, and `recv_signal` prints the
   same number.