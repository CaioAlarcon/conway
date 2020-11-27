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
    celula(bool);                           //Construtor, recebe informação inicial da vida da célula
    void adicionarVizinha(celula*);         //Permite que a vizinhança seja informada para a célula
    void defineEstado(bool);                //Define manualmente o estado da célula
    void defineEstadoView();                //Define estaddo baseado na cor da view
    void defineCorViva(sf::Color);          //Define qual cor da view a célula vai interpretar como viva
    void defineCorMorta(sf::Color);         //Define qual cor da view a célula vai interpretar como morta
    void processaProxG();                   //Processa próxima geração mas não muda o estado da célula, apenas guarda em VivaProxG
    void atualizaG();                       //Atualiza geração, ou seja, faz a célula associar o estado da próxima geração
    bool estadoAtual();                     //Externaliza estado atual da célula
    void cadastrarView(sf::RectangleShape*); //Insere objeto gráfico que representará a célula
    private:
    bool Viva;                              //Estado atual da célula
    bool VivaProxG;                         //Indica se a célula estará viva na próxima geração, caso já tenha sido calculada
    sf::Color corViva;                      //Representa qual cor da view a célula vai interpretar como viva
    sf::Color corMorta;                     //Representa qual cor da view a célula vai interpretar como morta
    std::set<celula*> vizinhas;             //Conjunto contendo células vizinhas
    sf::RectangleShape * visual;            //Parte gráfica que representa a célula
};
#endif
