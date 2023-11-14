#include "TADListaCadastral.h"
#ifndef OPERACOESNAOPRIMITIVAS_H_INCLUDED
#define OPERACOESNAOPRIMITIVAS_H_INCLUDED

void ImprimeLista(ListaCadastral &L) {
  string elemento;
  bool ok;
  PegaOPrimeiro(L, elemento, ok);
  while (ok) {
    cout << elemento << endl;
    pegaOProximo(L, elemento, ok);
  }
}

#endif // OPERACOESNAOPRIMITIVAS_H_INCLUDED
