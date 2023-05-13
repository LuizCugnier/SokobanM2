using namespace std;

struct Menu{
    bool principal = true;
    bool termina_jogo = true;

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
        int cont_passos = 0;
    };

struct Input{
    char tecla;
    char opcao_menu;
    

    void movimentos(Jogador* jogador, Menu &menu, int (&mj)[13][13]){
        if (_kbhit()){
            tecla = _getch();
            switch (tecla)
            {
            case 72: case 'w': //cima
                jogador->cont_passos++;

                if (jogador->x > 0 && mj[jogador->x - 1][jogador->y] == 0){//Se tem espaço livre o boneco anda
                    jogador->x--;
                } else if (mj[jogador->x - 1][jogador->y] == 2 && mj[jogador->x - 2][jogador->y] != 2 && mj[jogador->x - 2][jogador->y] != 1 ){//se tem uma caixa em cima, e todos os criterios são atendido, ele anda
                    mj[jogador->x - 2][jogador->y] = 2;
                    mj[jogador->x - 1][jogador->y] = 0;
                    jogador->x--;
                } else if (mj[jogador->x - 1][jogador->y] == 3){//Se tem o ponto final em cima
                    jogador->x--;
                }
                break;
            case 80: case 's': //baixo
                jogador->cont_passos++;

                if (jogador->x > 0 && mj[jogador->x + 1][jogador->y] == 0){
                    jogador->x++;
                } else if (mj[jogador->x + 1][jogador->y] == 2 && mj[jogador->x + 2][jogador->y] != 2 && mj[jogador->x + 2][jogador->y] != 1){
                    mj[jogador->x + 2][jogador->y] = 2;
                    mj[jogador->x + 1][jogador->y] = 0;
                    jogador->x++;
                } else if (mj[jogador->x + 1][jogador->y] == 3){
                    jogador->x++;
                }
                break;
            case 75: case 'a': //esquerda
                jogador->cont_passos++;

                if (jogador->y > 0 && mj[jogador->x][jogador->y - 1] == 0){
                    jogador->y--;
                } else if (mj[jogador->x][jogador->y - 1] == 2 && mj[jogador->x][jogador->y - 2] != 2 && mj[jogador->x][jogador->y - 2] != 1){
                    mj[jogador->x][jogador->y - 2] = 2;
                    mj[jogador->x][jogador->y - 1] = 0;
                    jogador->y--;
                } else if (mj[jogador->x][jogador->y - 1] == 3){
                    jogador->y--;
                }
                break;
            case 77: case 'd': //direita
                jogador->cont_passos++;

                if (jogador->y > 0 && mj[jogador->x][jogador->y + 1] == 0){
                    jogador->y++;
                } else if (mj[jogador->x][jogador->y + 1] == 2 && mj[jogador->x][jogador->y + 2] != 2 && mj[jogador->x][jogador->y + 2] != 1){
                    mj[jogador->x][jogador->y + 2] = 2;
                    mj[jogador->x][jogador->y + 1] = 0;
                    jogador->y++;
                } else if (mj[jogador->x][jogador->y + 1] == 3){
                    jogador->y++;
                }
                break;
            case 'r':
                //resetar o mapa
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
    int mx, my;
    int mj[13][13];

    void carrega_mapa(string arquivo_mapa){
        
        ifstream arquivo;
        arquivo.open(arquivo_mapa);

        if (arquivo.is_open()){
            arquivo >> mx >> my;
            //cout << mx << my;
            //cria_mapa();

            for (int i = 0; i < mx; i++){
                for (int j = 0;j < my; j++){
                    char c;
                    arquivo >> c;
                    mj[i][j] = (int)c - 48;
                }
            }
            arquivo.close();

        } else {
            cout << "erro";
        }
    }

    void imprime_mapa(Jogador* jogador, int (&mj)[13][13]){

        //Imprime o jogo: mapa e personagem.
        for (int i = 0; i < mx; i++) {
            for (int j = 0; j < my; j++) {
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
                    }

                }
                
            }
            cout << "\n"; 
        }
        cout << "\nCONTADOR DE PASSOS: " << jogador->cont_passos;
        cout << "\n\nAperte '0' para voltar";
    }
};
