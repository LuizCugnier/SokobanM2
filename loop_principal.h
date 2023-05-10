using namespace std;
struct Jogo{

    void novo_jogo(COORD coord, Mapa mapa, Input input, Jogador* jogador, Menu &menu, string arquivo_jogo){
        system("cls");
        menu.termina_jogo = true;

        while(menu.termina_jogo){
            //Posiciona no inicio do console
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            mapa.carrega_mapa(arquivo_jogo);
            mapa.imprime_mapa(jogador);
            mapa.movimentos(menu, jogador, input);
        }
        
    };

    void loop_principal(Menu &menu, Input input, COORD coord, Mapa mapa, Jogador* jogador, Jogo jogo, string arquivo_jogo){
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
                novo_jogo(coord, mapa, input, jogador, menu, arquivo_jogo);
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

};



