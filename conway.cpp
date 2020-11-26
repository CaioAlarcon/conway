#include "viewgame.h"

int main(){
    view janela(600,600,12,12);


    //o main inicializa o bang e fica aguardando por comandos via stdio
    //isso significa que o controller tem autonomia por thread
    while (janela.aberta()){
        janela.atualiza();
        sf::Time refresh = sf::seconds(0.048f);
        sf::sleep (refresh);
    }
    

    return 0;
}
