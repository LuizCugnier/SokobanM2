#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
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
    //x = 5, y = 5;

    Menu menu;
    //menu.principal = true;
    //menu.termina_jogo = true;

    Input input;
    input.tecla = 0;
    
    Jogador jogador;
    Jogador* Pjogador = &jogador;

    Mapa mapa;

    string arquivo_mapa = "C:/Users/gutoc/OneDrive/Imagens/Documentos/UNIVALI/algoeprog2/sokobanM2/SokobanV2.3/mapa3.txt";

    Jogo jogo;

    Dir dir;

    menu.imprime_menu();
    jogo.loop_principal(menu, input, coord, mapa, Pjogador, arquivo_mapa, dir);
    mapa.deleta_mapa();
    
    
    return 0;
}