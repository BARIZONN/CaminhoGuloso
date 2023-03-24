#include"file.h"
#include <fstream>
using namespace std;
int main() {
    ifstream file;
    unsigned contador = 0, matrix_counter = 0;
    unsigned short size, num, fileira, coluna;

    file.open("input.txt");

    if (file.is_open()) {

        tamanho(&file, &size);
        auto *matriz = (unsigned *) malloc(size *size * sizeof(unsigned));

        do {
            lermatriz(&file, &size, &num, matriz, &matrix_counter);
            col_lin(&fileira, &coluna);
            pos_inicial(&fileira, &coluna, &contador, matriz, &size);
            move(matriz,size, &fileira, &coluna, &contador);

            if (file.eof()) {
                cout << "Fim do percurso!" << endl;
                print(matriz,size);
                cout << "Soma: " << contador << endl;
                file.close();
                return 0;
            }
        } while (true);
    }
    return 0;
}