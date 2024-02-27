#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  kdTree arvore = create_kdTree();
  Point pontos[32];
  for (int i = 0; i < 32; i++) {
    void *new_value = malloc(sizeof("a"));
    new_value = (void *)"a";
    pontos[i] = _random_point();
    insert_element(&arvore, pontos[i], 2, new_value);
  }
  print_tree(&arvore);

  int a = 10;
  // char b = 'x';

  void *p = &a;
  printf("%d\n", *((int *)p));

  // print_tree(&arvore);

  return 0;
}
