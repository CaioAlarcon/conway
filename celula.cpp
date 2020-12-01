#include "celula.h"


//Public
celula::celula(bool viva){
    corViva = corViva.Blue;
    corMorta = corMorta.Red;
    Viva = viva;
}
void celula::adicionarVizinha(celula * Celula){
    if(Celula!=this)
        vizinhas.insert(Celula);
}
void celula::defineEstado(bool viva){
    this->Viva = viva;
}
void celula::defineEstadoView(){
    if(visual->getFillColor() == corViva)
        Viva = true;
    if(visual->getFillColor() == corMorta)
        Viva = false;
}
void celula::atualizaView(){
    if(Viva)
        visual->setFillColor(corViva);
    else
        visual->setFillColor(corMorta);
}
void celula::defineCorViva(sf::Color cor){
    corViva = cor;
}
void celula::defineCorMorta(sf::Color cor){
    corMorta = cor;
}
void celula::processaProxG(){//a thread tem que ver se tem alguém aqui dentro já, se já tiver vaza
    set<celula*>::iterator itr;
    int vidas=0;
    for (itr = vizinhas.begin();itr != vizinhas.end(); itr++){
        if((**itr).Viva)vidas++;
    }
    if(Viva){
        if(vidas == 2 || vidas == 3)
            VivaProxG = true;
        else
            VivaProxG = false;
    }else if(vidas == 3)
        VivaProxG = true;
    else
        VivaProxG = false;
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

//Private

