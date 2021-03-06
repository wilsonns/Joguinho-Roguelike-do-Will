#ifndef ENGINE_H
#define ENGINE_H

#include <main.h>
#include "Material.h"

class Engine
{
public:
    enum StatusJogo
    {
        INICIO,
        PARADO,
        TURNO_NOVO,
        TURNO_INIMIGO,
        VITORIA,
        DERROTA
    }statusJogo;//O status do jogo
    std::map<int, std::string> danoGdP;
    std::map<int, std::string> danoBal;

    int largura, altura; //Largura e altura da tela

    Mapa *mapa;//cria o mapa
    std::unordered_map<std::string,Material*> materiais;//cria a lista de materiais que sera utilizada no jogo
    Pathfinding* pathMapa;//cria o mapa de pathfinding compartilhado por todas as entidades que se movem
    std::vector<Entidade*> entidades;//cria uma std::vector de entidades livres no mapa(inimigos, itens)
    Entidade *jogador;//cria um pointer para o jogador
    Entidade* fim;//cria um pointer para 
    LOGGER *logger;//cria o log externo para debug
    GUI *gui;//Cria a interface do jogo
    
    TCOD_key_t ultimoBotao;
    TCOD_mouse_t mouse;

    bool rodando; //o jogo est� rodando?
    bool debug; // o jogo esta no modo debug?
    bool mostrarPath; //mostrar caminhos de cada entidade
    
    //CURSOR
    int cursx;
    int cursy;
    int cursSimb;
    int cursS;
    bool cursVisivel;
    
    Engine(int largura, int altura); //ctor
    virtual ~Engine();//dtor/

    int random(int minimo, int maximo, int bonus=0); // retorna um valor inteiro entre minimo e maximo + o bonus
    int randomf(float minimo, float maximo, float bonus=0);

    void mandarParaOInicio(Entidade* entidade);

    void atualizar(); //chama todas as fun��es de atualizar
    void render(); //chama todas as fun��es de render

protected:

private:
};

extern Engine engine; //Avisa o compilador que em algum dos arquivos .cpp tem a declara��o desse objeto;

#endif // ENGINE_H
