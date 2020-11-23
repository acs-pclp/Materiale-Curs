# Copyright 2020 Darius Neatu (neatudarius@gmail.com)

CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lm

SRCS = $(sort $(wildcard *.c))
TARGETS = $(patsubst %.c,%,$(SRCS))
TARGET = $(src:.c=)

# build all targets
all: $(TARGETS)

# general rule for building a target
%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

# run a single target
run: $(TARGET)
	./$(TARGET)

# clean all related target files
clean:
	rm -f *.o $(TARGETS)

# pack directory
pack:
	zip $(ZIP).zip *.c *.h Makefile README

.PHONY: pack clean
