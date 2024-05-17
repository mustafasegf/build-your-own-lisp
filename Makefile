CC = clang
CFLAGS = -std=c99 -Wall -Wextra -Werror -g
SRC = $(wildcard *.c)
EXE = $(SRC:.c=.bin)

all: $(EXE)

%.bin: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXE)
