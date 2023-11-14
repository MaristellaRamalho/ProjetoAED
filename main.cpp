#include <iostream>
#include "TADListaCadastral.h"
#include "OperacoesNaoPrimitivas.h"
using namespace std;

int main()
{
    ListaCadastral Playlist;
    Cria(Playlist);


    Inserir(Playlist, "Karma");
    Inserir(Playlist, "Nessa Cidade");
    Inserir(Playlist, "Ceu Azul");
    ImprimeLista(Playlist);

    Inserir(Playlist, "Animals");
    Inserir(Playlist, "Ceu Azul" );
    Inserir(Playlist, "Darkside");
    cout << endl ;
    ImprimeLista(Playlist);

    Retira(Playlist, "Karma");
    cout << endl ;
    ImprimeLista(Playlist);

    Retira(Playlist, "Love Love");
    cout << endl ;
    ImprimeLista(Playlist);
    cout << endl;


    string musica;
    bool ok;

    PegaOPrimeiro(Playlist, musica, ok);
    cout << "Musica: " << musica << endl;

    pegaOProximo(Playlist, musica, ok);
    cout << "Musica: " << musica << endl;

    pegaOAnterior(Playlist, musica, ok);
    cout << "Musica: " << musica << endl;

    return 0;
}













