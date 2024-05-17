CC = clang
CFLAGS = -std=c99 -Wall -Wextra -Werror -g
SRC = $(wildcard *.c)

all: $(SRC)
	$(CC) $(CFLAGS) -o main $(SRC)
