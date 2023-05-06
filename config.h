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

struct Input{
    char tecla;
    char opcao_menu;
};

    struct Jogador{
        int *x, *y;
    };

struct Mapa{
    int mj;

    void imprime_mapa(Jogador jogador, int (&mj)[13][13]){

        //Imprime o jogo: mapa e personagem.
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 13; j++) {
                if (i == jogador.x && j == jogador.y) {
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