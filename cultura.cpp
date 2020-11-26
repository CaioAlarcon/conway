#include "cultura.h"
#include <stdlib.h>

//quantas células tem
//atualizarviwew
//atualizar geração
//cadastrarobservernascelulas
//geração
cultura::cultura(int Largura, int Comprimento){
    this->Largura = Largura;
    this->Comprimento = Comprimento;
    //criar m por n células
    //atribuir as vizinhas
}

void cultura::criarCelulas(int m, int n){
    int i,j;
    this->Celulas = (celula**)malloc(sizeof(celula*)*m);
    for(i=0;i<m;i++)
        this->Celulas[i] = (celula*)malloc(sizeof(celula)*n);
    
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            this->Celulas[i][j] = new celula(false);

}
void cultura::adicionarVizinhos(){
    int j,i,X,Y;
    for(X=0;X<this->Largura;X++)
        for(Y=0;Y<this->Comprimento;Y++)
            for(i=-1;i<2;i++)
                for(j=-1;j<2;j++)
                    this->Celulas[X][Y].adicionarVizinha(this->Celulas[X + i ][Y + j]);
}

