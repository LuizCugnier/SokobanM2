#include <iostream>
#include <windows.h>
#include <conio.h>
#include "config.h"
#include "loop_principal.h"

using namespace std;

int main(){
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    //IN�CIO: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    short int CX = 0, CY = 0;
    COORD coord;
    coord.X = CX;
    coord.Y = CY;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, ACIMA.

    //posicao do jogador que vem do arquivo do mapa
    int x = 5, y = 5;

    Menu menu;
    menu.principal = true;
    menu.termina_jogo = true;

    Input input;
    input.tecla = 0;
    
    Jogador jogador;
    jogador.x = 5;
    jogador.y = 5;

    Mapa mapa;

    Mapa mj[13][13] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,
                        1,0,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,1,0,0,2,0,0,1,1,0,1,
                        1,0,0,1,0,0,0,0,0,0,1,0,1,
                        1,0,0,1,0,0,0,0,0,1,1,0,1,
                        1,0,0,1,0,0,0,0,0,0,0,0,1,
                        1,0,0,1,1,1,0,0,1,1,1,0,1,
                        1,0,0,0,0,0,0,0,0,0,1,0,1,
                        1,0,0,0,0,0,0,0,0,0,1,0,1,
                        1,0,0,0,0,0,3,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,0,1,
                        1,1,1,1,1,1,1,1,1,1,1,1,1 };

    Jogo jogo;

    menu.imprime_menu();
    jogo.jogo(menu, input, coord);
    
    return 0;
}