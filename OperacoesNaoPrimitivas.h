#include "TADListaCadastral.h"
#include "Musica.h"
#ifndef OPERACOESNAOPRIMITIVAS_H_INCLUDED
#define OPERACOESNAOPRIMITIVAS_H_INCLUDED

void ImprimeLista(ListaCadastral &L) {
    Musica musica;
    bool ok;

    if (Vazia(L)) {
        cout << "Playlist vazia :)" << endl;
        return;
    }

    PegaOPrimeiro(L, musica, ok);
    do {
        cout << "Nome: " << musica.getNome() << endl;
        cout << "Link: " << musica.getLink() << endl;
        pegaOProximo(L, musica, ok);
    } while (ok && L.Atual != L.Primeiro);
}


#endif // OPERACOESNAOPRIMITIVAS_H_INCLUDED
