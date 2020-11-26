#include "celula.h"


class cultura{
    public:
    cultura(int Largura, int Comprimento);
    private:
    void criarCelulas(int m, int n);
    void adicionarVizinhos();
    int Largura, Comprimento, Geracao;
    celula ** Celulas;
};



