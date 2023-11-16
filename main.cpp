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
    cout << "4 - Tocar proxima musica" << endl;
    cout << "5 - Tocar musica anterior" << endl;
    cout << "6 - Mostrar PlayList" << endl;
}


void povoarPlayList(ListaCadastral &P){
    Musica m1("Style", "https://www.youtube.com/watch?v=-CmadmM5cOk&list=RD-CmadmM5cOk&start_radio=1");
    Inserir(P, m1);

    Musica m2("I know its over" , "https://www.youtube.com/watch?v=M6o1SEj02t0&list=RDM6o1SEj02t0&start_radio=1");
    Inserir(P, m2);

    Musica m3("Julho" ,"https://www.youtube.com/watch?v=d9RM8viAKrw&list=RDd9RM8viAKrw&start_radio=1");
    Inserir(P, m3);

    Musica m4("Valentine", "https://www.youtube.com/watch?v=8XQYz7JKjWI");
    Inserir(P, m4);
}

int main() {
    // Criação e inicialização da lista
    ListaCadastral Playlist;
    Cria(Playlist);
    povoarPlayList(Playlist);

    imprimeMenu();
    int opcao;

    string nomeM, linkM;
    Musica musica;
    bool ok;

    do {
        cout << endl << "opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Saindo..." << endl;
                break;
            case 1:
                // Adicionar música
                cout << "Nome: ";
                cin >> nomeM;
                cout << "Link: ";
                cin >> linkM;
                musica.setNome(nomeM);
                musica.setLink(linkM);
                ok = Inserir(Playlist, musica);
                ok ? cout << "Musica adicionada com sucesso!" << endl : cout<<"Oops, musica ja adicionada"<<endl;
                break;
            case 2:
                // Remover Música
                cout << "Nome: ";
                cin >> nomeM;
                musica.setNome(nomeM);
                ok = Retira(Playlist, musica);
                ok ? cout << "Musica removida com sucesso!"<< endl: cout<<"Oops, musica nao encontrada"<<endl;
                break;

            case 3:
                // Tocar primeira musica
                PegaOPrimeiro(Playlist, musica, ok);
                ok ? cout << "Tocando : " << musica.getNome() << " | " << musica.getLink() << endl : cout << "Playlist vazia :(";
                break;
            case 4:
                // Tocar próxima música
                pegaOProximo(Playlist, musica, ok);
                ok ? cout << "Tocando : " << musica.getNome() << " | " << musica.getLink() << endl : cout << "Oops, sem proxima musica :(";
                break;
            case 5:
                // Tocar musica anterior
                pegaOAnterior(Playlist, musica, ok);
                ok ? cout << "Tocando : " << musica.getNome() << " | " << musica.getLink() << endl : cout << "Oops, sem musica anterior :(";
                break;
            case 6:
                // Mostrar Playlist
                cout << "SUA PLAYLIST " << endl;
                ImprimeLista(Playlist);
                break;
            default:
                cout << "Opçao invalida ";
        }
    } while (opcao != 0);
    return 0;
}
