#include "cultura.h"
#include <stdlib.h> 

//Public
cultura::cultura(int Largura, int Comprimento){
    int i;

    inicializaJanela(Largura,Comprimento);
    
    
    threadEventos = new thread(&cultura::eventos, this);
    threadEventos->detach();

    
    controle = new thread(&cultura::controlador, this);
    controle->detach();
    for(i=0;i<4;i++){
        Automacao[0] = new thread(&cultura::ProcessaAutomato, this);
        Automacao[0]->detach();
    }
    automato->NotificaraTodos(sem_controle);//Semaforo de controle será notificado quando automato terminar
    
    
}
void cultura::inicializaJanela(){
    inicializaJanela(Largura,Comprimento);
}
void cultura::reiniciaCultura(){
    janela->randomizaShapes();
    viewAlterada = true;
    associaValores();
}
void cultura::limparCultura(){
    janela->limpaShapes();
    viewAlterada = true;
    associaValores();
}

void cultura::inicializaJanela(int largura,int comprimento){
    Largura = largura;
    Comprimento = comprimento;
    
    janela = new view(600,600,largura,comprimento);
    criarCelulas();
    adicionarVizinhos();
    
    setViews(janela->getViews());//adiciona referencia da matriz de shapes na cultura
    
    associaViews();//insere views nas células
    //associaValores();//atribui valor da view às células
    
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
    if(viewAlterada)
        for(i=0;i<Largura;i++)
            for(j=0;j<Comprimento;j++)
                Celulas[i][j]->defineEstadoView();
    viewAlterada = false;
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
void cultura::proxGen(){
    int i,j;
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
void cultura::ProcessaAutomato(){
    int i,j;
    while (true){
        automato->wait();
        for(i=0;i<Largura;i++)
            for(j=0;j<Comprimento;j++)
                getCelula(i,j)->processaProxG();
    }
    
}
void cultura::controlador(){
    while(true){
        
        if(Reiniciar){
            reiniciaCultura();
            Reiniciar = false;
        }
        if(Limpar){
            limparCultura();
            Limpar = false;
        }
        if(!Pause){
            
            associaValores();         //Valores da view para as células
            automato->notifyall();    //inicia processo liberando todas as threads
            sem_controle->wait();     //espera notificação do processo que foi iniciado
            proxGen();
            atualizaView();            //valores das células para a view
        }
        
        
        atualizaGrafico();//limpa a tela, desenha tudo de novo
        this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

//se os eventos não ficarem sendo tratados constantemente a janela trava e o sistema emite msg falando que o programa não está respondendo.
void cultura::eventos(){
    sf::Event event;
    
    while(true){
        while (janela->getWindow()->pollEvent(event)){
            if(event.type == sf::Event::Closed)
                exit(0);
            
            lidaComMouse(event);
            lidaComTeclado(event);
        }
        sf::sleep(sf::milliseconds(12.0f));
       
    }
}

void cultura::lidaComTeclado(sf::Event event){
    switch (event.type){
        case sf::Event::KeyReleased:
            
        break;
        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::Space) Pause = !Pause;
            if(event.key.control){
                if(event.key.code == sf::Keyboard::C)
                    Limpar = true;
                if(event.key.code == sf::Keyboard::R)
                    Reiniciar = true;
                if(event.key.code == sf::Keyboard::E)
                    exit(0);
            }
            
         break;
    }
}
void cultura::onClick(sf::Event event){
    int i, j, M, N;
    sf::RectangleShape *** shapes;
    shapes = janela->getViews();
    
    M = janela->linhas();
    N = janela->colunas();
    
    sf::Color cor;
    

    for(i=0;i<M;i++)
            for(j=0;j<N;j++){
                sf::FloatRect Box(shapes[i][j]->getPosition().x, shapes[i][j]->getPosition().y, 
                                                shapes[i][j]->getSize().x, shapes[i][j]->getSize().y);
                
                if(Box.contains(event.mouseButton.x,event.mouseButton.y)){
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
                        shapes[i][j]->setFillColor(cor.Red);
                    else
                        shapes[i][j]->setFillColor(cor.Blue);
                    viewAlterada = true;
                }
                
            }
}
void cultura::onMove(sf::Event event){
    int i, j, M, N;
    M = janela->linhas();
    N = janela->colunas();
    sf::RectangleShape *** shapes;
    if(mouseDownw){
        shapes = janela->getViews();
        sf::Color cor;
        
        
        for(i=0;i<M;i++)
                for(j=0;j<N;j++){
                    sf::FloatRect Box(shapes[i][j]->getPosition().x, shapes[i][j]->getPosition().y, 
                                                    shapes[i][j]->getSize().x, shapes[i][j]->getSize().y);
                    
                    if(Box.contains(event.mouseMove.x,event.mouseMove.y)){
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
                            shapes[i][j]->setFillColor(cor.Red);
                        else
                            shapes[i][j]->setFillColor(cor.Blue);

                        
                        viewAlterada=true;
                    }
                    
                }
    }
}
void cultura::lidaComMouse(sf::Event event){
    int i, j,M,N;
    sf::Color cor;
    M = janela->linhas();
    N = janela->colunas();
    
    switch(event.type){
        case sf::Event::MouseButtonPressed:
            mouseDownw = true;
            //janela->getWindow()->setTitle("apertou");
            onClick(event);
        break;
        case sf::Event::MouseMoved:
            onMove(event);
            //janela->getWindow()->setTitle("moveu");
        break;
        case sf::Event::MouseButtonReleased:
            mouseDownw = false;
            //janela->getWindow()->setTitle("soltou");
        break;
    }

    
    
}

