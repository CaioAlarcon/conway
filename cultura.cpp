#include "cultura.h"
#include <stdlib.h> 

//Public
cultura::cultura(int Largura, int Comprimento){
    this->Largura = Largura;
    this->Comprimento = Comprimento;
    janela = new view(600,600,64,64);
    
    criarCelulas();
    adicionarVizinhos();
    
    setViews(janela->getViews());//adiciona referencia da matriz de shapes na cultura
    
    associaViews();//insere views nas células
    
    associaValores();//atribui valor da view às células
    
    


    controle = new thread(&cultura::controlador, this);
    controle->detach();
    
    
    
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
void cultura::setViews(sf::RectangleShape *** views){
    retangulos = views;
}
void cultura::associaValores(){
    int i,j;
    for(i=0;i<Largura;i++)
        for(j=0;j<Comprimento;j++)
            Celulas[i][j]->defineEstadoView();

}
celula * cultura::getCelula(int x,int y){

    return  Celulas [x%(unsigned int)Largura][y%(unsigned int)Comprimento];
}
void cultura::atualizaView(){
    int i,j;
    for(i=0;i<Largura;i++)
        for(j=0;j<Comprimento;j++)
            getCelula(i,j)->atualizaView();
}
void cultura::proxGen(){//essa função tem que ser duas, cada qual com seu semaforo diferente
    int i,j;
    for(i=0;i<Largura;i++)
        for(j=0;j<Comprimento;j++)
            getCelula(i,j)->processaProxG();
    //int i,j;
    for(i=0;i<Largura;i++)
        for(j=0;j<Comprimento;j++)
            getCelula(i,j)->atualizaG();
}
void cultura::atualizaGrafico(){
    janela->atualiza();
}

//Private

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
                    this->Celulas[X][Y]->adicionarVizinha(getCelula(X+i,Y+j));
}
void cultura::controlador(){
    

    while(true){
        this->atualizaGrafico();
        this->proxGen();

        this->atualizaView();
        this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}