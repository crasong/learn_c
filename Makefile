CC = gcc
CFLAGS = -Wall -Wextra -Ithird_party -lraylib -lm

learn_c: main.c
	$(CC) $(CFLAGS) main.c -o learn_c

clean:
	rm -f learn_c
