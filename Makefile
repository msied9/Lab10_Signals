CC=gcc
CFLAGS=-c -g -Wall -Werror
PROGS=signal_handler signal_alarm signal_segfault signal_sigaction recv_signal send_signal

all: $(PROGS)

$(PROGS): %: %.o
	$(CC) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o $(PROGS)
