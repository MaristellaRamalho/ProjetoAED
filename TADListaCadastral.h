#ifndef TADLISTACADASTRAL_H_INCLUDED
#define TADLISTACADASTRAL_H_INCLUDED
#include <iostream>
#include <string.h>
using namespace std;

// Lista Cadastral sem elementos repetidos, não ordenada, implementada como uma lista duplamente encadeada circular.

struct Node {
  string info;
  struct Node *esq;
  struct Node *dir;
};

typedef struct Node *NodePtr;

typedef struct Lista {
  NodePtr Atual;
  NodePtr Primeiro;
} ListaCadastral;

void Cria(ListaCadastral &L) {
  L.Atual = NULL;
  L.Primeiro = NULL;
}

bool Vazia(ListaCadastral &L) { return L.Primeiro == NULL; }

bool EstaNalista(ListaCadastral &L, string elemento){
  if(!Vazia(L)){
    NodePtr P = L.Primeiro;
    do{ // faz pelo menos uma vez
        if(P->info == elemento)
            return true;
        P = P->dir;
  }while( P != L.Primeiro); // não dar loop infinito
  return false;
  }

}


bool Inserir(ListaCadastral &L, string elemento) {
  NodePtr NovoNo = new Node;
  if (NovoNo != NULL) {
    NovoNo->info = elemento;
    if (Vazia(L)) { // se a lista estiver vazia
      NovoNo->esq = NovoNo;
      NovoNo->dir = NovoNo;
      L.Atual = NovoNo;
      L.Primeiro = NovoNo;
    } else {
      if(!EstaNalista(L, elemento)){ // se não estiver na lista
        NodePtr Ultimo = L.Primeiro->esq;
        NovoNo->esq = Ultimo;
        NovoNo->dir = L.Primeiro;
        Ultimo->dir = NovoNo;
        L.Primeiro->esq = NovoNo;
      }
    }
    return true; // Inserção bem-sucedida
  } else {
    return false;
  }
}

bool Retira(ListaCadastral &L, string elemento) {
  if (!EstaNalista(L, elemento)) { // inclui possibilidade de lista vazia
    return false;
  }
  NodePtr PAux = L.Primeiro;
  do {
    // se o elemento procurado for o único da lista
    if (PAux->dir == PAux && PAux->info == elemento ){
      delete PAux;
      L.Primeiro = NULL;
    }
    // Se existirem mais de um elemento na lista e o elemento apontado por PAux for o elemento procurado
    else if (PAux->info == elemento) {
      PAux->esq->dir = PAux->dir;
      PAux->dir->esq = PAux->esq;
      L.Primeiro = PAux->dir;
      delete PAux;
    }
    PAux = PAux->dir;
  } while (PAux != L.Primeiro);
  return true;
}

void pegaOProximo(ListaCadastral &L, string &elemento, bool &TemElemento) {
  if (Vazia(L))
    TemElemento = false;
  else {
    if (L.Atual != NULL)
      L.Atual = L.Atual->dir;
    if (L.Atual == L.Primeiro)
      TemElemento = false;
    else{
        TemElemento = true;
        elemento = L.Atual->info;
    }
  }
}

void pegaOAnterior(ListaCadastral &L, string &elemento, bool &TemElemento) {
  if (Vazia(L))
    TemElemento = false;
  else {
    if (L.Atual != NULL)
      L.Atual = L.Atual->esq;
    if (L.Atual == L.Primeiro)
      TemElemento = false;
    else
      TemElemento = true;
    elemento = L.Atual->info;
  }
    }

void PegaOPrimeiro(Lista &L, string &elemento, bool &TemElemento) {
  if (Vazia(L))
    TemElemento = false;
  else {
    L.Atual = L.Primeiro;
    elemento = L.Atual->info;
    TemElemento = true;
  }
}

#endif // TADLISTACADASTRAL_H_INCLUDED
