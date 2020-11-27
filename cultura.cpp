#include "cultura.h"
#include <stdlib.h>


cultura::cultura(int Largura, int Comprimento){
    this->Largura = Largura;
    this->Comprimento = Comprimento;
    criarCelulas();
    adicionarVizinhos();
}
void cultura::criarCelulas(){
    int i,j,m,n;
    m=Largura;
    n=Comprimento;
    Celulas = (celula***)malloc(sizeof(celula*)*m);
    for(i=0;i<m;i++)
        Celulas[i] = (celula**)malloc(sizeof(celula)*n);
    
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            Celulas[i][j] = new celula(false);

}
void cultura::adicionarVizinhos(){
    int j,i,X,Y;
    for(X=0;X<this->Largura;X++)
        for(Y=0;Y<this->Comprimento;Y++)
            for(i=-1;i<2;i++)
                for(j=-1;j<2;j++)
                    this->Celulas[X][Y]->adicionarVizinha(this->Celulas[X+i][Y+j]);
}
void cultura::defineVida(int largura, int comprimento, bool vivo){
    Celulas[largura][comprimento]->defineEstado(vivo);
}
void cultura::associaViews(){
    int i,j;
    for(i=0;i<Largura;i++)
        for(j=0;j<Comprimento;j++)
            Celulas[i][j]->cadastrarView(retangulos[i][j]);

}
void cultura::associaValores(){
    int i,j;
    for(i=0;i<Largura;i++)
        for(j=0;j<Comprimento;j++)
            Celulas[i][j]->defineEstadoView();

}
