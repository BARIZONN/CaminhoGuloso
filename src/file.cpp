#include "file.h"
using namespace std;

void tamanho(ifstream *file, unsigned short *tamanho) {
    *file >> *tamanho;
    *file >> *tamanho;
}

void lermatriz(ifstream *file, unsigned short *tamanho, unsigned short *num, unsigned *matrix,
                 unsigned *contador) {
    ++(*contador);
    cout << "Matriz de número: " << *contador << endl;
    for (unsigned short i = 0; i < *tamanho; i++) {
        for (unsigned short j = 0; j < *tamanho; j++) {
            do {
                *file >> *num;
                if (*num != '\n') {
                    matrix[*tamanho * i + j] = *num;
                    cout << matrix[*tamanho * i + j] << ' ';
                }
                if (file->eof()) {
                    break;
                }
            } while (*num == '\n');
        }
        cout << endl;
    }
    cout << endl;;
}

void col_lin(unsigned short *fileira, unsigned short *coluna) {
    cout << "Digite a posicao inicial:\n Fileira:" << endl;
    cin >> *fileira;
    cout << "Coluna:" << endl;
    cin >> *coluna;
    cout << endl;
}

void pos_inicial(unsigned short *fileira, unsigned short *coluna, unsigned *counter, unsigned *matrix,
                          unsigned short *tamanho) {
    *counter = matrix[*tamanho * (*fileira) + (*coluna)];
    matrix[*tamanho * (*fileira) + (*coluna)] = 0;
}

void move(unsigned *matrix, unsigned short tamanho, unsigned short *fileira, unsigned short *coluna, unsigned *counter) {
    do {
        if ((*fileira == (tamanho - 1) && *fileira == *coluna)) {
            break;
        } else if (*fileira == (tamanho - 1)) {
            leste(matrix, tamanho, &(*fileira), &(*coluna), &(*counter));
        } else if (*coluna == (tamanho - 1)) {
            if (matrix[tamanho * ((*fileira) + 1) + (*coluna)] >= matrix[tamanho * ((*fileira) + 1) + ((*coluna) - 1)] &&
                matrix[tamanho * ((*fileira) + 1) + (*coluna)] >= matrix[tamanho * (*fileira) + ((*coluna) - 1)]) {
                sul(matrix, tamanho, &(*fileira), &(*coluna), &(*counter));
            } else if (matrix[tamanho * (*fileira) + ((*coluna) - 1)] >= matrix[tamanho * ((*fileira) + 1) + ((*coluna) - 1)]) {
                oeste(matrix, tamanho, &(*fileira), &(*coluna), &(*counter));
            } else {
                sudoeste(matrix, tamanho, &(*fileira), &(*coluna), &(*counter));
            }
        } else if (*coluna == 0) {
            if (matrix[tamanho * ((*fileira) + 1) + ((*coluna) + 1)] >= matrix[tamanho * ((*fileira) + 1) + (*coluna)] &&
                matrix[tamanho * ((*fileira) + 1) + ((*coluna) + 1)] >= matrix[tamanho * (*fileira) + ((*coluna) + 1)]) {
                sudeste(matrix, tamanho, &(*fileira), &(*coluna), &(*counter));
            } else if (matrix[tamanho * (*fileira) + ((*coluna) + 1)] >= matrix[tamanho * ((*fileira) + 1) + (*coluna)]) {
                leste(matrix, tamanho, &(*fileira), &(*coluna), &(*counter));
            } else {
                sul(matrix, tamanho, &(*fileira), &(*coluna), &(*counter));
            }
        } else if (matrix[tamanho * ((*fileira) + 1) + ((*coluna) + 1)] >= matrix[tamanho * (*fileira) + ((*coluna) + 1)] &&
                   matrix[tamanho * ((*fileira) + 1) + ((*coluna) + 1)] >= matrix[tamanho * ((*fileira) + 1) + (*coluna)] &&
                   matrix[tamanho * ((*fileira) + 1) + ((*coluna) + 1)] >= matrix[tamanho * (*fileira) + ((*coluna) - 1)] &&
                   matrix[tamanho * ((*fileira) + 1) + ((*coluna) + 1)] >= matrix[tamanho * ((*fileira) + 1) + ((*coluna) - 1)]) {
            sudeste(matrix, tamanho, &(*fileira), &(*coluna), &(*counter));
        } else if (matrix[tamanho * (*fileira) + ((*coluna) + 1)] >= matrix[tamanho * ((*fileira) + 1) + (*coluna)] &&
                   matrix[tamanho * (*fileira) + ((*coluna) + 1)] >= matrix[tamanho * (*fileira) + ((*coluna) - 1)] &&
                   matrix[tamanho * (*fileira) + ((*coluna) + 1)] >= matrix[tamanho * ((*fileira) + 1) + ((*coluna) - 1)]) {
            leste(matrix, tamanho, &(*fileira), &(*coluna), &(*counter));
        } else if (matrix[tamanho * ((*fileira) + 1) + (*coluna)] >= matrix[tamanho * ((*fileira) + 1) + ((*coluna) - 1)] &&
                   matrix[tamanho * ((*fileira) + 1) + (*coluna)] >= matrix[tamanho * (*fileira) + ((*coluna) - 1)]) {
            sul(matrix, tamanho, &(*fileira), &(*coluna), &(*counter));
        } else if (matrix[tamanho * (*fileira) + (*coluna - 1)] >= matrix[tamanho * ((*fileira) + 1) + ((*coluna) - 1)])
            oeste(matrix, tamanho, &(*fileira), &(*coluna), &(*counter));
        else {
            sudoeste(matrix, tamanho, &(*fileira), &(*coluna), &(*counter));
        }
    } while (true);
}


void leste(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter) {
    *counter += matrix[size * (*row) + (++(*column))];
    matrix[size * (*row) + (*column)] = 0;
}

void sul(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter) {
    *counter += matrix[size * (++(*row)) + (*column)];
    matrix[size * (*row) + (*column)] = 0;
}

void oeste(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter) {
    *counter += matrix[size * (*row) + (--(*column))];
    matrix[size * (*row) + (*column)] = 0;
}

void sudeste(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter) {
    *counter += matrix[size * (++(*row)) + (++(*column))];
    matrix[size * (*row) + (*column)] = 0;
}

void sudoeste(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter) {
    *counter += matrix[size * (++(*row)) + (--(*column))];
    matrix[size * (*row) + (*column)] = 0;
}

void print(unsigned *matrix, unsigned short size) {
    for (unsigned short i = 0; i < size; i++) {
        for (unsigned short j = 0; j < size; j++) {
            cout << matrix[size * i + j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}