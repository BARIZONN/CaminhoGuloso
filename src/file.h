#ifndef FILE_H
#define FILE_H
#include <fstream>
#include <iostream>
using namespace std;

void tamanho(ifstream *file, unsigned short *size);
void lermatriz(ifstream *file, unsigned short *size, unsigned short *num, unsigned *matrix, unsigned *matrix_counter);
void col_lin(unsigned short *row, unsigned short *column);
void pos_inicial(unsigned short *row, unsigned short *column, unsigned *counter, unsigned *matrix, unsigned short *size);
void print(unsigned *matrix, unsigned short size);
void leste(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter);
void sul(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter);
void oeste(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter);
void sudeste(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter);
void sudoeste(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter);
void move(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter);
#endif 
