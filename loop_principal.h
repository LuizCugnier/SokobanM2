using namespace std;
void loop_principal(Menu menu, Input input, COORD coord, Mapa mapa, Jogador* jogador, Jogo jogo, int (&mj)[13][13]){
    while (menu.principal){
        
        if (_kbhit()){
            input.tecla = _getch();

            switch (input.tecla)
            {
            case '0':
                //imprimir o menu novamente
                menu.imprime_menu();
                break;
            case '1':
                //cria um novo jogo
                //jogo.novo_jogo(mapa, input, jogador, menu, mj);
                system("cls");
                menu.termina_jogo = true;

                while(menu.termina_jogo){
                    //Posiciona no inicio do console
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

                    mapa.imprime_mapa(jogador, mj);
                    input.input(menu, jogador, mj);
                }
                break;
            case '2':
                //continua um jogo
                
                break;
            case '3':
                //informações do jogo
                break;
            case '4':
                //termina jogo
                menu.principal = false;
                break;
            default:
                break;
            }
        }
    }
}

