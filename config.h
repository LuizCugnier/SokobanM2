using namespace std;

struct Menu{
    bool principal = true;
    bool termina_jogo = true;

    void imprime_menu(){
        system("cls");
        cout << "===============================================================================================================\n";
        cout << R"(
         ___             __   ___         _                  ___      _       _               
        | _ ) ___ _ __   \ \ / (_)_ _  __| |___   __ _ ___  / __| ___| |_____| |__  __ _ _ _  
        | _ \/ -_) '  \   \ V /| | ' \/ _` / _ \ / _` / _ \ \__ \/ _ \ / / _ \ '_ \/ _` | ' \ 
        |___/\___|_|_|_|   \_/ |_|_||_\__,_\___/ \__,_\___/ |___/\___/_\_\___/_.__/\__,_|_||_|
                                                                                            
        )" << endl;
        cout << "===============================================================================================================\n";
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

struct Dir {

    void cima(Jogador* jogador, Menu &menu, int** mj){

        if (jogador->x > 0 && mj[jogador->x - 1][jogador->y] == 0){//Se tem espaço livre o boneco anda
            jogador->cont_passos++;
            jogador->x--;
        } else if (mj[jogador->x - 1][jogador->y] == 2){//se tem uma caixa em cima
            if (mj[jogador->x - 2][jogador->y] == 0){
                mj[jogador->x - 2][jogador->y] = 2;
                mj[jogador->x - 1][jogador->y] = 0;
                jogador->cont_passos++;
                jogador->x--;
            } else if (mj[jogador->x - 2][jogador->y] == 3){    
                mj[jogador->x - 2][jogador->y] = 4;
                mj[jogador->x - 1][jogador->y] = 0;
                jogador->cont_passos++;
                jogador->x--;
            }
        } else if (mj[jogador->x - 1][jogador->y] == 3){//Se tem o ponto final em cima
            jogador->cont_passos++;
            jogador->x--;   
        } else if (mj[jogador->x - 1][jogador->y] == 4){//Se tem uma caixa no ponto final
            if(mj[jogador->x - 2][jogador->y] == 0){
                mj[jogador->x - 2][jogador->y] = 2;
                mj[jogador->x - 1][jogador->y] = 3;
                jogador->cont_passos++;
                jogador->x--;
            } else if (mj[jogador->x - 2][jogador->y] == 3){
                mj[jogador->x - 2][jogador->y] = 4;
                mj[jogador->x - 1][jogador->y] = 3;
            }
        }
    }

    void baixo(Jogador* jogador, Menu &menu, int** mj){

        if (jogador->x > 0 && mj[jogador->x + 1][jogador->y] == 0){
            jogador->cont_passos++;
            jogador->x++;
        } else if (mj[jogador->x + 1][jogador->y] == 2){
            if (mj[jogador->x + 2][jogador->y] == 0){
                mj[jogador->x + 2][jogador->y] = 2;
                mj[jogador->x + 1][jogador->y] = 0;
                jogador->cont_passos++;
                jogador->x++;
            } else if (mj[jogador->x + 2][jogador->y] == 3){    
                mj[jogador->x + 2][jogador->y] = 4;
                mj[jogador->x + 1][jogador->y] = 0;
                jogador->cont_passos++;
                jogador->x++;
            }
        } else if (mj[jogador->x + 1][jogador->y] == 3){
            jogador->cont_passos++;
            jogador->x++;
        } else if (mj[jogador->x + 1][jogador->y] == 4){//Se tem uma caixa no ponto final
            if (mj[jogador->x + 2][jogador->y] == 0){
                mj[jogador->x + 2][jogador->y] = 2;
                mj[jogador->x + 1][jogador->y] = 3;
                jogador->cont_passos++;
                jogador->x++;
            }else if (mj[jogador->x + 2][jogador->y] == 3){
                mj[jogador->x + 2][jogador->y] = 4;
                mj[jogador->x + 1][jogador->y] = 3;
                jogador->cont_passos++;
                jogador->x++;
            }
        }
    }

    void esquerda(Jogador* jogador, Menu &menu, int** mj){

        if (jogador->y > 0 && mj[jogador->x][jogador->y - 1] == 0){
            jogador->cont_passos++;
            jogador->y--;
        } else if (mj[jogador->x][jogador->y - 1] == 2){
            if (mj[jogador->x][jogador->y - 2] == 0){
                mj[jogador->x][jogador->y - 2] = 2;
                mj[jogador->x][jogador->y - 1] = 0;
                jogador->cont_passos++;
                jogador->y--;
            } else if (mj[jogador->x][jogador->y - 2] == 3){
                mj[jogador->x][jogador->y - 2] = 4;
                mj[jogador->x][jogador->y - 1] = 0;
                jogador->cont_passos++;
                jogador->y--;
            }
        } else if (mj[jogador->x][jogador->y - 1] == 3){
            jogador->cont_passos++;
            jogador->y--;
        } else if (mj[jogador->x][jogador->y - 1] == 4){
            if (mj[jogador->x][jogador->y - 2] == 0){
                mj[jogador->x][jogador->y - 2] = 2;
                mj[jogador->x][jogador->y - 1] = 3;
                jogador->cont_passos++;
                jogador->y--;
            } else if(mj[jogador->x][jogador->y - 2] == 3){
                mj[jogador->x][jogador->y - 2] = 4;
                mj[jogador->x][jogador->y - 1] = 3;
                jogador->cont_passos++;
                jogador->y--;
            }
        }
    }

    void direita(Jogador* jogador, Menu &menu, int** mj){

        if (jogador->y > 0 && mj[jogador->x][jogador->y + 1] == 0){
            jogador->cont_passos++;
            jogador->y++;
        } else if (mj[jogador->x][jogador->y + 1] == 2){
            if (mj[jogador->x][jogador->y + 2] == 0){
                mj[jogador->x][jogador->y + 2] = 2;
                mj[jogador->x][jogador->y + 1] = 0;
                jogador->cont_passos++;
                jogador->y++;
            } else if (mj[jogador->x][jogador->y + 2] == 3){
                mj[jogador->x][jogador->y + 2] = 4;
                mj[jogador->x][jogador->y + 1] = 0;
                jogador->cont_passos++;
                jogador->y++;
            }
        } else if (mj[jogador->x][jogador->y + 1] == 3){
            jogador->cont_passos++;
            jogador->y++;
        } else if (mj[jogador->x][jogador->y + 1] == 4){
            if (mj[jogador->x][jogador->y + 2] == 0){
                mj[jogador->x][jogador->y + 2] = 2;
                mj[jogador->x][jogador->y + 1] = 3;
                jogador->cont_passos++;
                jogador->y++;;
            }else if(mj[jogador->x][jogador->y + 2] == 3){
                mj[jogador->x][jogador->y + 2] = 4;
                mj[jogador->x][jogador->y + 1] = 3;
                jogador->cont_passos++;
                jogador->y++;
            }
        }
    }
};

struct Input{
    char tecla;
    char opcao_menu;
    

    void movimentos(Jogador* jogador, Menu &menu, int** mj, Dir dir){
        if (_kbhit()){
            tecla = _getch();
            switch (tecla)
            {
            case 72: case 'w': //cima
                dir.cima(jogador, menu, mj);
                break;
            case 80: case 's': //baixo
                dir.baixo(jogador, menu, mj);
                break;
            case 75: case 'a': //esquerda
                dir.esquerda(jogador, menu, mj);
                break;
            case 77: case 'd': //direita
                dir.direita(jogador, menu, mj);
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
    int **mj;

    void cria_mapa(){
        mj = new int*[mx];

        for (int i=0; i < mx; i++){
            mj[i] = new int[my];
        }
    }

    void deleta_mapa(){
        for(int i = 0; i < mx; i++){
            delete mj[i];
        }
        delete mj;
    }

    void carrega_mapa(string arquivo_mapa, Jogador* jogador){
        
        ifstream arquivo;
        arquivo.open(arquivo_mapa);


        if (arquivo.is_open()){
            arquivo >> mx >> my;
            arquivo >> jogador->x >> jogador->y;

            cria_mapa();
            
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

    void imprime_mapa(Jogador* jogador, int** mj){

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
