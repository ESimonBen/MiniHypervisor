CC = gcc
CFLAGS = -Wall -Wextra -O2

SRC = src/main.c
OUT = build/hypervisor

all:
	mkdir -p build
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -rf build