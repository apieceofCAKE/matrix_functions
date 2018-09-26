/*
Função que preeche uma matriz de inteiros de ordem n_lin x n_col com números pseudoaleatórios inteiros
de 1 a 32 (usar rand)
Função que receba uma matriz mat de inteiros e compute o histograma dos valores de mat.
O histograma é um array int hist[32] que armazena a frequência de cada inteiro &{0,31} em mat
Função para imprimir a matriz void imprimir
Desafio: Função que receba uma matriz mat_in de dimensões n_lin x n_col
e gere  outra matriz mat_out de dimensão n_lin/2 x n_col/2 onde um elemento mat_out[i][j] = MAX{mat[i][j],
mat[i+1][j], mat[i][j+1], mat[i+1[j+1]}
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_LIN_MAX 100
#define N_COL_MAX 100

//Declaration
void preencher_matriz(int mat[N_LIN_MAX][N_COL_MAX], int n_lin, int n_col);
void calcular_histogram(int mat[N_LIN_MAX][N_COL_MAX], int n_lin, int n_col, int histograma[32]);
void imprimir(int mat[N_LIN_MAX][N_COL_MAX], int n_lin, int n_col);


//Main function
int main() {

    int n_lin, n_col;


    time_t t;
    srand((unsigned int) time(&t));

    printf("\nNúmero de linhas: ");
    scanf("%d", &n_lin);

    printf("\nNúmero de colunas: ");
    scanf("%d", &n_col);

    int mat[n_lin][n_col];

    preencher_matriz(mat, n_lin, n_col);

    printf("\n\nCalculando histograma...\n");

    int histograma[32];
    calcular_histogram(mat, n_lin, n_col, histograma);

    printf("\nImprimindo a matriz...\n\n");

    imprimir(mat, n_lin, n_col);
    return 0;
}

//Definition
void preencher_matriz(int mat[N_LIN_MAX][N_COL_MAX], int n_lin, int n_col) {

    for (int aux1 = 0; aux1 < n_lin; aux1 ++) {
        for (int aux2 = 0; aux2 < n_col; aux2 ++) {

            mat[aux1][aux2] = rand() % 32;
        }
    }
}

void calcular_histogram(int mat[N_LIN_MAX][N_COL_MAX], int n_lin, int n_col, int histograma[32]) {

    int k;

    for (int aux0 = 0; aux0 < 32; aux0 ++) {
        histograma[aux0] = 0;
    }

    for (int aux1 = 0; aux1 < n_lin; aux1 ++) {
        for (int aux2 = 0; aux2 < n_col; aux2 ++) {

            k = mat[aux1][aux2];
            histograma[k] ++;
        }
    }

    for (int aux3 = 0; aux3 < 32; aux3 ++) {
        printf(" %d ", histograma[aux3]);
    }
}

void imprimir(int mat[N_LIN_MAX][N_COL_MAX], int n_lin, int n_col) {


    for (int aux1 = 0; aux1 < n_lin; aux1 ++) {
        printf("\n");
        for (int aux2 = 0; aux2 < n_col; aux2 ++) {
            printf(" %d ", mat[aux1][aux2]);
        }
    }
}
