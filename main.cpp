#include <iostream>
#include "TADListaCadastral.h"
#include "OperacoesNaoPrimitivas.h"
#include "Musica.h"
using namespace std;

int main()
{
    ListaCadastral Playlit;
    Cria(Playlit);

    Musica musica1("Gossip", "https://www.youtube.com/watch?v=9IPLXNEzsLc&list=RD9IPLXNEzsLc&start_radio=1");
    Musica musica2("Style", "https://www.youtube.com/watch?v=-CmadmM5cOk&list=RD9IPLXNEzsLc&index=3&pp=8AUB");

    Inserir(Playlit, musica1);
    Inserir(Playlit, musica2);

    cout << "Playlist: " << endl;
    ImprimeLista(Playlit);

    return 0;
}












