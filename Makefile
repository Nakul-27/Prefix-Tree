
CC=gcc
CFLAGS=-Wall -Werror -ggdb3

default: trie.c
	$(CC) $(CFLAGS) -o trie trie.c

test: trie
	./trie

mem: trie
	valgrind --leak-check=yes --track-origins=yes ./trie
