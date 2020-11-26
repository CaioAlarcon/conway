#include "celula.h"

celula::celula(bool viva){
    this->Viva = viva;
}
void celula::adicionarVizinha(celula Celula){
    vizinhas.insert(&Celula);
}
void celula::defineEstado(bool viva){
    this->Viva = viva;
}
