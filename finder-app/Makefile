# finder-app/Makefile
# Default target: build writer for the native platform.
# Cross-compile: make CROSS_COMPILE=aarch64-none-linux-gnu-

CROSS_COMPILE ?=
CC      = $(CROSS_COMPILE)gcc
CFLAGS  = -Wall -Wextra -g
TARGET  = writer
OBJS    = writer.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) *.o

.PHONY: clean
