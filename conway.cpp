#include "viewgame.h"
#include "cultura.h"
#include <stdio.h>

int main(){
    //view janela(600,600,64,64);

    

    //o main inicializa o bang e fica aguardando por comandos via stdio
    //isso significa que o controller tem autonomia por thread

    //criar a cultura   new cultura
    cultura cult(64,64);
    
    //enfiar nela a view   cultura.addviwe(janela.view)
    
    
    
    //botar pra rodar       
    //primeiro atualizar geração cultura.atualiza()
    //depois ir pra próxima geração cultura.next()
    //umas coisa assim



    while (true){
        
        sf::Time refresh = sf::seconds(8.8f);
        sf::sleep (refresh);
        
        //
        //se o pause não estiver ativado

        
    
    }


    return 0;
}
