#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Trie Trie;

struct Trie{
  Trie* children;
};

// TODO: Implement
/* void print_tree(Trie* root) { */
/*   if (root -> children == NULL) { */
/*     return; */
/*   } else { */
/*     return; */
/*   } */
/* } */

#define TRIE_NODE_CAP 1024
size_t trie_node_count = 0;

Trie* alloc_node(void) {
  assert(trie_node_count < TRIE_NODE_CAP);

  Trie* node = (Trie*)malloc(sizeof(Trie));
  node -> children = NULL;

  trie_node_count += 1;

  return node;
}

void insert(Trie* root, const char* text) {
  assert(root != NULL && text != NULL);

  if (*text == '\0') {
    return;
  }

  size_t index = (size_t)* text;

  if (&root -> children[index] == NULL) {
    // TODO: Look into *alloc_node()
    root -> children[index] = *alloc_node();
  }

  // TODO: Look into &root
  insert(&root -> children[index], text + 1);
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
  insert(root, "Hello");
  printf("Hello World");
  return 0;
}
