# Copyright Ionescu Matei-Stefan - 313CAb - 2021-2022
# compiler setup
CC=gcc
CFLAGS=-g -Wall -Wextra -std=c99

# define targets
DEPEND=main.c linked_list.c commands.c utils.c 

build: tema1

tema1: $(DEPEND)
		$(CC) $(CFLAGS) $(DEPEND) -o tema1
pack:
		zip -FSr 313CA_IonescuMateiStefan_Tema1.zip README.md Makefile *.c *.h

clean:
		rm -f tema1 *.o

.PHONY: pack clean