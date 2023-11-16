#include "TADListaCadastral.h"
#include "Musica.h"
#ifndef OPERACOESNAOPRIMITIVAS_H_INCLUDED
#define OPERACOESNAOPRIMITIVAS_H_INCLUDED

void ImprimeLista(ListaCadastral &L) {
  Musica musica;
  bool ok;
  PegaOPrimeiro(L, musica, ok);
  while (ok) {
    cout << "Nome: " << musica.getNome() << endl;
    cout << "Link: " << musica.getLink() << endl;;
    pegaOProximo(L, musica, ok);
  }
}

#endif // OPERACOESNAOPRIMITIVAS_H_INCLUDED
