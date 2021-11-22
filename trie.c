#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Trie Trie;

struct Trie{
  bool leaf;
  Trie** children;
};

// TODO: Implement
/* void print_tree(Trie* root) { */
/*   if (root -> children == NULL) { */
/*     return; */
/*   } else { */
/*     return; */
/*   } */
/* } */

Trie* alloc_node(void) {
  Trie* node = (Trie*)malloc(sizeof(Trie));
  // TODO: Look into this
  node -> children = malloc(sizeof(char));
  node -> leaf = false;
  return node;
}

void insert(Trie* root, const char* text) {
  assert(root != NULL && text != NULL);

  /* printf("%s\n", text); */

  if (*text == '\0') {
    root -> leaf = true;
    return;
  }

  size_t index = (size_t)* text;
  if (root -> children[index] == NULL) {
    printf("%s\n", text);
    root -> children[index] = alloc_node();
  }

  /* printf("%lu\n", (size_t)sizeof(text)); */
  /* if (root -> children[index] == NULL) { */
  /*   printf("%s\n", text); */
  /*   root -> children = alloc_node(26); */
  /* } */

  /* if (root -> children[index] == NULL) { */
  /*   // TODO: Look into *alloc_node() */
  /*   root -> children[index] = *alloc_node(50); */
  /* } */

  // TODO: Look into &root
  insert(root -> children[index], text + 1);
}

void print_trie(Trie* root, const char* word) {
  int i;

  if (root == NULL) {
    return;
  }

  if (root -> leaf == true) {
    printf("%s\n", word);
  }
  
  for (i = 0; i < 26; ++i) {
    if (&root -> children[i] != NULL) {
      print_trie(root -> children[i], word);
    }
  }
}

/* void free_trie(Trie* root) { */
/*   assert(root != NULL); */

/*   if (root -> children == NULL) { */
/*     free(root); */
/*     return; */
/*   } */
/* } */

int main() {
  Trie* root = alloc_node();
  insert(root, "Hi");
  insert(root, "Hello");
  insert(root, "This");
  /* print_trie(root, "Hi"); */
  /* printf("Hello World\n"); */
  return 0;
}
