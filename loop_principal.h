using namespace std;
struct Jogo{
    bool jogo_ativo = false;

    void loop_jogo(COORD coord, Mapa &mapa, Input input, Jogador* jogador, Menu &menu){
        while(menu.termina_jogo){
            //Posiciona no inicio do console
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            mapa.imprime_mapa(jogador, mapa.mj);
            input.movimentos(jogador, menu, mapa.mj);
        }
    }

    void novo_jogo(COORD coord, Mapa &mapa, Input input, Jogador* jogador, Menu &menu, string arquivo_jogo){
        system("cls");
        menu.termina_jogo = true;
        jogo_ativo = true;
        jogador->cont_passos = 0;
        mapa.carrega_mapa(arquivo_jogo, jogador);
        
        loop_jogo(coord, mapa, input, jogador, menu);
        
    };

    void continua_jogo(COORD coord, Mapa &mapa, Input input, Jogador* jogador, Menu &menu, string arquivo_jogo){
        if (jogo_ativo) {
            system("cls");
            menu.termina_jogo = true;

            loop_jogo(coord, mapa, input, jogador, menu);

        } else {
            cout << "INICIE UM NOVO JOGO PRIMEIRO!!!";
            Sleep(650);
            system("cls");
            menu.imprime_menu();
        }
    };

    void sobre_jogo(){
        system("cls");
        cout << "informacoes aqui(preencher depois)";
    }

    void termina_jogo(Menu &menu){
        menu.principal = false;
        system("cls");
    };

    void loop_principal(Menu &menu, Input input, COORD coord, Mapa &mapa, Jogador* jogador, string arquivo_jogo){
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
                    continua_jogo(coord, mapa, input, jogador, menu, arquivo_jogo);
                    break;
                case '3':
                    //informações do jogo
                    sobre_jogo();
                    break;
                case '4':
                    //termina jogo
                    termina_jogo(menu);
                    break;
                default:
                    break;
                }
            }
        }
    }

};



