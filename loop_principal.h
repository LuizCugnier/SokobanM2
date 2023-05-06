using namespace std;
struct Jogo{

    void jogo(Menu menu, Input input, Mapa mapa, Mapa &mj, Jogador jogador, COORD coord){
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
