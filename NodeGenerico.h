#ifndef NODEGENERICO_H_INCLUDED
#define NODEGENERICO_H_INCLUDED
#include <iostream>

template <typename T> // permite flexibilidade de tipo

struct Node {
  T info; // O tipo do campo info pode ser qualquer um
  struct Node *esq;
  struct Node *dir;
};



#endif // NODEGENERICO_H_INCLUDED
