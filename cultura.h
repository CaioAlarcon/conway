#include "celula.h"

//quantas células tem
//atualizarviwew
//atualizar geração
//cadastrarobservernascelulas
//geração
class cultura{
    public:
    cultura(int Largura, int Comprimento);      //Construtor baseado no tamanho bidimensional
    private:
    void criarCelulas();                        //Cria as células necessárias
    void adicionarVizinhos();                   //Adiciona os vizinhos para cada célula
    int Largura, Comprimento, Geracao;          //Variáveis privadas
    celula ** Celulas;                          //Array dinâmico contendo endereço das células
};



