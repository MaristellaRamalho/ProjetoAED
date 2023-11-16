#ifndef TADLISTACADASTRAL_H_INCLUDED
#define TADLISTACADASTRAL_H_INCLUDED
#include <iostream>
#include <string.h>
#include "NodeGenerico.h"
#include "Musica.h"
using namespace std;

// Lista Cadastral sem elementos repetidos, n�o ordenada, implementada como uma lista duplamente encadeada circular. O tipo de elemento da lista será Musica


// Definindo um tipo para o Node que contem o campo info do tipo Musica
typedef Node<Musica> NodeMusica;

// Definindo um tipo que corresponde a um ponteiro para Node<Musica>
typedef NodeMusica* NodePtr;


typedef struct Lista {
  NodePtr Atual;
  NodePtr Primeiro;
} ListaCadastral;

void Cria(ListaCadastral &L) {
  L.Atual = NULL;
  L.Primeiro = NULL;
}

bool Vazia(ListaCadastral &L) { return L.Primeiro == NULL; }

bool EstaNalista(ListaCadastral &L, Musica musica){
  if(!Vazia(L)){
    NodePtr P = L.Primeiro;
    do{ // faz pelo menos uma vez
        if(P->info.getNome() == musica.getNome())
            return true;
        P = P->dir;
  }while( P != L.Primeiro); // n�o dar loop infinito
  return false;
  }

}


bool Inserir(ListaCadastral &L, Musica musica) {
  NodePtr NovoNo = new NodeMusica;
  if (NovoNo != NULL) {
    NovoNo->info.setNome(musica.getNome());
    NovoNo->info.setLink(musica.getLink());
    if (Vazia(L)) { // se a lista estiver vazia
      NovoNo->esq = NovoNo;
      NovoNo->dir = NovoNo;
      L.Atual = NovoNo;
      L.Primeiro = NovoNo;
      return true;
    } else {
      if(!EstaNalista(L, musica) && musica.getNome() != "Sem nome" && musica.getLink() != "Sem link") { // se nao estiver na lista e se for um nome valido
        NodePtr Ultimo = L.Primeiro->esq;
        NovoNo->esq = Ultimo;
        NovoNo->dir = L.Primeiro;
        Ultimo->dir = NovoNo;
        L.Primeiro->esq = NovoNo;
        return true;
      }else{
          return false; // não inseriu
      }
    }
  } else {
    return false; // não alocou
  }
}


bool Retira(ListaCadastral &L, Musica musica) {
  if (!EstaNalista(L, musica)) { // inclui possibilidade de lista vazia
    return false;
  }
  NodePtr PAux = L.Primeiro;
  do {
    // se o elemento procurado for o unico da lista
    if (PAux->dir == PAux && PAux->info.getNome() == musica.getNome() ){
      delete PAux;
      L.Primeiro = NULL;
      return true;
    }
    // Se existirem mais de um elemento na lista e o elemento apontado por PAux for o elemento procurado
    else if (PAux->info.getNome() == musica.getNome()) {
      PAux->esq->dir = PAux->dir;
      PAux->dir->esq = PAux->esq;
      delete PAux;
      return true;
    }
    PAux = PAux->dir;
  } while (PAux != L.Primeiro);
  return false;
}

void pegaOProximo(ListaCadastral &L, Musica &musica, bool &TemElemento) {
  if (Vazia(L))
    TemElemento = false;
  else {
    if (L.Atual != NULL)
      L.Atual = L.Atual->dir;
    if (L.Atual == L.Primeiro)
      TemElemento = false;
    else{
        TemElemento = true;
        musica.setNome(L.Atual->info.getNome());
        musica.setLink(L.Atual->info.getLink());
    }
  }
}

void pegaOAnterior(ListaCadastral &L, Musica &musica, bool &TemElemento) {
  if (Vazia(L))
    TemElemento = false;
  else {
    if (L.Atual != NULL)
      L.Atual = L.Atual->esq;
    if (L.Atual == L.Primeiro)
      TemElemento = false;
    else
      TemElemento = true;
    musica.setNome(L.Atual->info.getNome());
    musica.setLink(L.Atual->info.getLink());
  }
    }

void PegaOPrimeiro(Lista &L, Musica &musica, bool &TemElemento) {
  if (Vazia(L))
    TemElemento = false;
  else {
    L.Atual = L.Primeiro;
    musica.setNome(L.Atual->info.getNome());
    musica.setLink(L.Atual->info.getLink());
    TemElemento = true;
  }
}




#endif // TADLISTACADASTRAL_H_INCLUDED
