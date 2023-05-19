using namespace std;
struct Jogo{
    bool jogo_ativo = false;

    void loop_jogo(COORD coord, Mapa &mapa, Input input, Jogador* jogador, Menu &menu, Dir dir){
        while(menu.termina_jogo){
            //Posiciona no inicio do console
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            mapa.imprime_mapa(jogador, mapa.mj);
            input.movimentos(jogador, menu, mapa.mj, dir);
        }
    }

    void novo_jogo(COORD coord, Mapa &mapa, Input input, Jogador* jogador, Menu &menu, string arquivo_jogo, Dir dir){
        system("cls");
        menu.termina_jogo = true;
        jogo_ativo = true;
        jogador->cont_passos = 0;
        mapa.escolhe_mapa(arquivo_jogo);
        mapa.carrega_mapa(arquivo_jogo, jogador );
        system("cls");
        
        loop_jogo(coord, mapa, input, jogador, menu, dir);
        
    };

    void continua_jogo(COORD coord, Mapa &mapa, Input input, Jogador* jogador, Menu &menu, string arquivo_jogo, Dir dir){
        if (jogo_ativo) {
            system("cls");
            menu.termina_jogo = true;

            loop_jogo(coord, mapa, input, jogador, menu, dir);

        } else {
            cout << "INICIE UM NOVO JOGO PRIMEIRO!!!";
            Sleep(800);
            system("cls");
            menu.imprime_menu();
        }
    };

    void sobre_jogo(){
        system("cls");
        cout << "=======================\n";
        cout << "    REGRAS DO JOGO     \n";
        cout << "=======================\n";

        cout << "\n->Objetivo do jogo eh posicionar as caixas no ponto final no menor numero de movimentos.\n";
        cout << "\nAperte '0' para voltar ao menu.";
    }

    void termina_jogo(Menu &menu){

        menu.principal = false;
        system("cls");
        cout << R"(

   ____  ____  _____  _____ _____          _____   ____    _____   ____  _____         _  ____   _____          _____  
  / __ \|  _ \|  __ \|_   _/ ____|   /\   |  __ \ / __ \  |  __ \ / __ \|  __ \       | |/ __ \ / ____|   /\   |  __ \ 
 | |  | | |_) | |__) | | || |  __   /  \  | |  | | |  | | | |__) | |  | | |__) |      | | |  | | |  __   /  \  | |__) |
 | |  | |  _ <|  _  /  | || | |_ | / /\ \ | |  | | |  | | |  ___/| |  | |  _  /   _   | | |  | | | |_ | / /\ \ |  _  / 
 | |__| | |_) | | \ \ _| || |__| |/ ____ \| |__| | |__| | | |    | |__| | | \ \  | |__| | |__| | |__| |/ ____ \| | \ \ 
  \____/|____/|_|  \_\_____\_____/_/    \_\_____/ \____/  |_|     \____/|_|  \_\  \____/ \____/ \_____/_/    \_\_|  \_\
                                                                                                                       
                                                                                                                       
        )" << endl;
        Sleep(1500);
        system("cls");
    };

    void loop_principal(Menu &menu, Input input, COORD coord, Mapa &mapa, Jogador* jogador, string arquivo_jogo, Dir dir){
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
                    novo_jogo(coord, mapa, input, jogador, menu, arquivo_jogo, dir);
                    break;
                case '2':
                    //continua um jogo
                    continua_jogo(coord, mapa, input, jogador, menu, arquivo_jogo, dir);
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



