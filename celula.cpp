#include "celula.h"

celula::celula(bool viva){
    this->Viva = viva;
}
void celula::adicionarVizinha(celula * Celula){
    if(Celula!=this)
        vizinhas.insert(Celula);
}
void celula::defineEstado(bool viva){
    this->Viva = viva;
}
void celula::processaProxG(){
    set<celula*>::iterator itr;
    int vidas=0;
    for (itr = vizinhas.begin();itr != vizinhas.end(); itr++){
        if((**itr).Viva)vidas++;
    }
    if(Viva){
        if(vidas == 2 || vidas == 3)
            Viva = true;
        else
            Viva = false;
    }else if(vidas == 3)
        Viva = true;
    else
        Viva = false;
}
void celula::atualizaG(){
    Viva = VivaProxG;
}
bool celula::estadoAtual(){
    return Viva;
}
void celula::cadastrarView(sf::RectangleShape * shape){
    visual = shape;
}