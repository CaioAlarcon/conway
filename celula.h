#include <SFML/Graphics.hpp>
#include <set>

using namespace std;

#ifndef _celula_
#define _celula_
class celula{
    //add vizinhas, usar um set
    //cadastrar observer usando ponteiro pra função
    //processa automato
    //
    public:
    celula(bool);
    void adicionarVizinha(celula);
    void defineEstado(bool);
    private:
    bool Viva;
    std::set<celula*> vizinhas;
};
#endif
