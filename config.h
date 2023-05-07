using namespace std;

struct Menu{
    bool principal;
    bool termina_jogo;

    void imprime_menu(){
        system("cls");
        cout << "=======================\n";
        cout << "Bem Vindo ao Sokoban\n";
        cout << "=======================\n";
        cout << "[1] Novo Jogo\n";
        cout << "[2] Continuar\n";
        cout << "[3] Sobre\n";
        cout << "[4] Fim\n";
    }

};

struct Jogador{
        int x, y;
    };

struct Input{
    char tecla;
    char opcao_menu;

    void input(Menu &menu, Jogador* jogador, int (&mj)[13][13]){
        if (_kbhit()){
            tecla = _getch();
            switch (tecla)
            {
            case 72: case 'w': //cima
                if (jogador->x > 0 && mj[jogador->x - 1][jogador->y] == 0){
                    jogador->x--;
                } else if (mj[jogador->x - 1][jogador->y] == 2 && mj[jogador->x - 2][jogador->y] != 2 && mj[jogador->x - 2][jogador->y] != 1 ){
                    mj[jogador->x - 2][jogador->y] = 2;
                    mj[jogador->x - 1][jogador->y] = 0;
                    jogador->x--;
                }
                break;
            case 80: case 's': //baixo
                if (jogador->x > 0 && mj[jogador->x + 1][jogador->y] == 0){
                    jogador->x++;
                } else if (mj[jogador->x + 1][jogador->y] == 2 && mj[jogador->x + 2][jogador->y] != 2 && mj[jogador->x + 2][jogador->y] != 1){
                    mj[jogador->x + 2][jogador->y] = 2;
                    mj[jogador->x + 1][jogador->y] = 0;
                    jogador->x++;
                }
                break;
            case 75: case 'a': //esquerda
                if (jogador->y > 0 && mj[jogador->x][jogador->y - 1] == 0){
                    jogador->y--;
                } else if (mj[jogador->x][jogador->y - 1] == 2 && mj[jogador->x][jogador->y - 2] != 2 && mj[jogador->x][jogador->y - 2] != 1){
                    mj[jogador->x][jogador->y - 2] = 2;
                    mj[jogador->x][jogador->y - 1] = 0;
                    jogador->y--;
                }
                break;
            case 77: case 'd': //direita
                if (jogador->y > 0 && mj[jogador->x][jogador->y + 1] == 0){
                    jogador->y++;
                } else if (mj[jogador->x][jogador->y + 1] == 2 && mj[jogador->x][jogador->y + 2] != 2 && mj[jogador->x][jogador->y + 2] != 1){
                    mj[jogador->x][jogador->y + 2] = 2;
                    mj[jogador->x][jogador->y + 1] = 0;
                    jogador->y++;
                }
                break;
            case '0': //volta menu
                menu.termina_jogo = false;
                system("cls");
                menu.imprime_menu();
                break;
            default:
                break;
            }
        }
    }
};

struct Mapa{

    void imprime_mapa(Jogador* jogador, int (&mj)[13][13]){

        //Imprime o jogo: mapa e personagem.
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 13; j++) {
                if (i == jogador->x && j == jogador->y) {
                    cout << char(2); //personagem
                }
                
                else {
                    switch (mj[i][j]) {
                    case 0: cout << " "; break; //caminho
                    case 1: cout << char(219); break; //parede
                    case 2: cout << "#"; break; //caixa em espaço vazio
                    case 3: cout << "."; break; //posição final
                    case 4: cout << "&"; break; //caixa na posição final
                        //default: cout<<"-"; //erro
                    } //fim switch

                }
                
            }
            cout << "\n";
        } //fim for mapa[

        cout << "\nAperte '0' para voltar";
    }
};

struct Jogo{

    void novo_jogo(COORD coord, Mapa mapa, Input input, Jogador* jogador, Menu& menu, int (&mj)[13][13]){
        system("cls");
        menu.termina_jogo = true;

        while(menu.termina_jogo){
            //Posiciona no inicio do console
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            mapa.imprime_mapa(jogador, mj);
            input.input(menu, jogador, mj);
        }
        
    };
};