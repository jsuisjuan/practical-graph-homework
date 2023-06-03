#include <iostream>
#include <stdio.h>
#include "implementation-header.cpp"
using namespace std;
/*
    Tasks:
    - fazer entrada e saida como o trab pede
    - integrar tudo utilizando o header(refatoracao tbm)
    - fazer essa de componente conexo
*/
int main(int argc, char *argv[]) {
    cout<< header_test()<<endl;

    FILE *arquivo;
    int numero = 0, i = 0;
    int valores[3];

    arquivo = fopen("teste.txt", "r");
    if (!arquivo) {
        printf("Arquivo nao esta abrindo.");
        return 1;
    }
    while (fscanf(arquivo, "%d,", &numero) > 0) {
        if (i < 3) valores[i] = numero;
        else {
            grafo.adicionarAresta(valores[0], valores[1], valores[2]);
            i = 0;
            valores[i] = numero;
        }
        i++;
    }
    fclose(arquivo);
    return 0;
}