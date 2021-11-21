#!/bin/sh

set -xe

cc -Wall -Werror -std=c11 -ggdb3 -o trie trie.c
