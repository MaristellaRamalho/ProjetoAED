#include <iostream>
#include "TADListaCadastral.h"
#include "OperacoesNaoPrimitivas.h"
#include "Musica.h"
using namespace std;

void imprimeMenu() {
    cout << "-------- MENU -------" << endl;
    cout << "0 - Sair" << endl;
    cout << "1 - Adicionar musica" << endl;
    cout << "2 - Remover musica" << endl;
    cout << "3 - Tocar primeira musica" << endl;
    cout << "4 - Ir para proxima musica" << endl;
    cout << "5 - Voltar para musica anterior" << endl;
    cout << "6 - Mostrar PlayList" << endl;
}

int main() {
    ListaCadastral Playlist;
    // Criação e inicialização da lista

    imprimeMenu();
    int opcao;

    do {
        cout << endl << "opcao: ";
        cin >> opcao;

        string nomeM, linkM;
        Musica musica;


        switch (opcao) {
            case 0:
                cout << "Saindo..." << endl;
                goto fim_programa;
            case 1:
                // Adicionar música
                cout << "Nome: ";
                cin >> nomeM;
                cout << "Link: ";
                cin >> linkM;
                musica.setNome(nomeM);
                musica.setLink(linkM);
                Inserir(Playlist, musica);

                break;
            case 6:
                // Mostrar Playlist
                ImprimeLista(Playlist);
                break;
            // outros cases
        }
    } while (opcao != 0);

    fim_programa:
    return 0;
}
