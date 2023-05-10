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

};

struct Mapa{
    int mj[13][13];
    int mx, my;

    void carrega_mapa(string arquivo_mapa){
        
        ifstream arquivo;
        arquivo.open(arquivo_mapa);

        if (arquivo.is_open()){
            arquivo >> mx >> my;
            //cout << mx << my;
            for (int i = 0; i < mx; i++){
                for (int j = 0;j < my; j++){
                    char c;
                    arquivo >> c;
                    mj[i][j] = c;
                }
            }
            arquivo.close();

        } else {
            cout << "erro";
        }
    }

    void imprime_mapa(Jogador* jogador){

        //Imprime o jogo: mapa e personagem.
        for (int i = 0; i < mx; i++) {
            for (int j = 0; j < my; j++) {
                if (i == jogador->x && j == jogador->y) {
                    cout << char(2); //personagem
                }
                
                else {
                    switch (mj[i][j]) {
                    case '0': cout << " "; break; //caminho
                    case '1': cout << char(219); break; //parede
                    case '2': cout << "#"; break; //caixa em espaço vazio
                    case '3': cout << "."; break; //posição final
                    case '4': cout << "&"; break; //caixa na posição final
                    }

                }
                
            }
            cout << "\n"; 
        }

        cout << "\nAperte '0' para voltar";
    }

    void movimentos(Menu &menu, Jogador* jogador, Input input){
        if (_kbhit()){
            input.tecla = _getch();
            switch (input.tecla)
            {
            case 72: case 'w': //cima
                if (jogador->x > 0 && mj[jogador->x - 1][jogador->y] == '0'){
                    jogador->x--;
                } else if (mj[jogador->x - 1][jogador->y] == '2' && mj[jogador->x - 2][jogador->y] != '2' && mj[jogador->x - 2][jogador->y] != '1' ){
                    mj[jogador->x - 2][jogador->y] = '2';
                    mj[jogador->x - 1][jogador->y] = '0';
                    jogador->x--;
                }
                break;
            case 80: case 's': //baixo
                if (jogador->x > 0 && mj[jogador->x + 1][jogador->y] == '0'){
                    jogador->x++;
                } else if (mj[jogador->x + 1][jogador->y] == '2' && mj[jogador->x + 2][jogador->y] != '2' && mj[jogador->x + 2][jogador->y] != '1'){
                    mj[jogador->x + 2][jogador->y] = '2';
                    mj[jogador->x + 1][jogador->y] = '0';
                    jogador->x++;
                }
                break;
            case 75: case 'a': //esquerda
                if (jogador->y > 0 && mj[jogador->x][jogador->y - 1] == '0'){
                    jogador->y--;
                } else if (mj[jogador->x][jogador->y - 1] == '2' && mj[jogador->x][jogador->y - 2] != '2' && mj[jogador->x][jogador->y - 2] != '1'){
                    mj[jogador->x][jogador->y - 2] = '2';
                    mj[jogador->x][jogador->y - 1] = '0';
                    jogador->y--;
                }
                break;
            case 77: case 'd': //direita
                if (jogador->y > 0 && mj[jogador->x][jogador->y + 1] == '0'){
                    jogador->y++;
                } else if (mj[jogador->x][jogador->y + 1] == '2' && mj[jogador->x][jogador->y + 2] != '2' && mj[jogador->x][jogador->y + 2] != '1'){
                    mj[jogador->x][jogador->y + 2] = '2';
                    mj[jogador->x][jogador->y + 1] = '0';
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
