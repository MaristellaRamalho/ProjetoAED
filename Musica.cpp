#include "Musica.h"
#include <iostream>
using namespace std;

 // Musica(string nomeM="Sem nome", string linkM="Sem link");
   //     string getNome();
     //   string getLink();
       // bool setNome(string nomeM);
        //bool setLink(string linkM);

Musica::Musica(string nomeM, string linkM)
{
    nome = stringVazia(nomeM) ? "Sem nome" : nomeM;
    link = stringVazia(linkM) ? "Sem link" : linkM;
}


string Musica:: getNome() const{
    return nome;
}

string Musica:: getLink() const{
    return link;
}

bool Musica:: setNome(string nomeM){
    if(stringVazia(nomeM))
        return false;
    nome = nomeM;
    return true;
}

bool Musica:: setLink(string linkM){
    if(stringVazia(linkM))
        return false;
    link = linkM;
    return true;
}

bool Musica:: stringVazia(const string& str){
    return std::all_of(str.begin(), str.end(), [](unsigned char ch) {
        return std::isspace(ch);
    });
}
