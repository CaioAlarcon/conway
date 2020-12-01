#include "celula.h"
#include <thread>
#include "viewgame.h"

//quantas células tem
//atualizarviwew
//atualizar geração
//cadastrarobservernascelulas
//geração
class cultura{
    public:
    cultura(int Largura, int Comprimento);      //Construtor baseado no tamanho bidimensional
    
    void defineVida(int, int, bool);            //alterar o valor das células individualmente
    void associaViews();                        //atribuir as views às células
    void associaValores();                      //atribuir valores das views às células
    void proxGen();                             //próxima geração
    void setViews(sf::RectangleShape ***);
    celula * getCelula(int,int);                //retorna a celula da posição x, y
    void atualizaView();                        //Atualiza estado da view baseadod no estado da cultura
    void atualizaGrafico();
    
    private:
    void criarCelulas();                        //Cria as células necessárias
    void adicionarVizinhos();                   //Adiciona os vizinhos para cada célula
    int Largura, Comprimento, Geracao;          //Variáveis privadas
    celula *** Celulas = NULL;                  //Array dinâmico contendo endereço das células
    sf::RectangleShape *** retangulos = NULL;   //Array dinâmico contendo endereços das views
    void controlador();
    view * janela;
    thread * controle;
};



