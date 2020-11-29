#include "viewgame.h"
#include "cultura.h"
#include <stdio.h>

int main(){
    view janela(600,600,64,64);

    printf("%p",janela.getViews());

    //o main inicializa o bang e fica aguardando por comandos via stdio
    //isso significa que o controller tem autonomia por thread

    //criar a cultura   new cultura
    cultura cult(64,64);
    
    //enfiar nela a view   cultura.addviwe(janela.view)
    cult.setViews(janela.getViews());//adiciona referencia da matriz de shapes na cultura
    
    cult.associaViews();//insere views nas células
    
    cult.associaValores();//atribui valor da view às células
    
    cult.proxGen();         //calcula próxima geração e 

    cult.atualizaView();
    
    
    //botar pra rodar       
    //primeiro atualizar geração cultura.atualiza()
    //depois ir pra próxima geração cultura.next()
    //umas coisa assim


    while (janela.aberta()){
        janela.atualiza();
        sf::Time refresh = sf::seconds(0.048f);
        sf::sleep (refresh);
        
        cult.proxGen();
        cult.atualizaView();
    
    }
    

    return 0;
}
