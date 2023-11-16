#ifndef MUSICA_H
#define MUSICA_H
#include <iostream>
#include <algorithm>  // Para std::all_of

using namespace std;

class Musica
{
    private:
        string nome;
        string link;

    public:
        Musica(string nomeM="Sem nome", string linkM="Sem link");
        string getNome() const;
        string getLink() const;
        bool setNome(string nomeM);
        bool setLink(string linkM);
        static bool stringVazia(const string& str);

};

#endif // MUSICA_H
