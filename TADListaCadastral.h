#ifndef TADLISTACADASTRAL_H_INCLUDED
#define TADLISTACADASTRAL_H_INCLUDED
#include <iostream>
#include <string.h>
#include "NodeGenerico.h"
#include "Musica.h"
using namespace std;

// Problema na funçao PegaOAnterior
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
    if (!EstaNalista(L, musica) || Vazia(L)) {
        // Se a lista estiver vazia ou o elemento não estiver presente, retorna falso
        return false;
    }

    NodePtr PAux = L.Primeiro;

    do {
        //Caso seja o único elemento
        if (PAux->dir == PAux && PAux->info.getNome() == musica.getNome() ){
              delete PAux;
              L.Primeiro = NULL;
              return true;
        }
        else if (PAux->info.getNome() == musica.getNome()) {
            if (PAux == L.Primeiro) {
                // Se o elemento a ser removido for o primeiro
                L.Primeiro = PAux->dir;
            }

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
    if (Vazia(L)) {
        TemElemento = false;
        return;
    }

    if (L.Atual != NULL) {
        L.Atual = L.Atual->dir;
    } else {
        // Se L.Atual for NULL, estamos no final da lista. Volte para o início.
        L.Atual = L.Primeiro;
    }

    TemElemento = true;
    musica.setNome(L.Atual->info.getNome());
    musica.setLink(L.Atual->info.getLink());
}

void pegaOAnterior(ListaCadastral &L, Musica &musica, bool &TemElemento) {
    if (Vazia(L)) {
        TemElemento = false;
        return;
    }

    if (L.Atual != NULL) {
        L.Atual = L.Atual->esq;
    } else {
        // Se L.Atual for NULL, estamos no início da lista. Avance para o final.
        L.Atual = L.Primeiro->esq;
    }

    TemElemento = true;
    musica.setNome(L.Atual->info.getNome());
    musica.setLink(L.Atual->info.getLink());
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
