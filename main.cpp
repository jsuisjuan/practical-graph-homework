#include <iostream>
#include <stdio.h>
#include <list>
#include "./header/graph.h"

using namespace std;
/*
    Tasks:
    - fazer entrada e saida como o trab pede
    - integrar tudo utilizando o header(refatoracao tbm)
    - fazer essa de componente conexo

    saida: 
        numero de vertice;
        numero de arestas;
        grau medio;
        distribuicao empirica do grau de vertice.
 */

int menu();

int main(int argc, char *argv[]) {
    /* cout<< header_test()<<endl;

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
    fclose(arquivo); */

    int opcao;
    do {
        opcao = menu();
        switch(opcao){
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
        }
    } while(op1 != 0);
   
    int V=8;
    Grafo grafo(V);
    grafo.adicionar_aresta(0, 1);
    grafo.adicionar_aresta(0,1,3);
    grafo.adicionar_aresta(0, 2);
    grafo.adicionar_aresta(1, 3);
    grafo.adicionar_aresta(1, 4);
    grafo.adicionar_aresta(2, 5);
    grafo.adicionar_aresta(2, 6);
    grafo.adicionar_aresta(6, 7);
    grafo.dfs(0); 
    //grafo.bfs(0);
    return 0;
}

int menu() {
    int opcao;
    cout << "\n\n\n----Menu Principal----\n\n"
         << "\n1.Inserir no na arvore"
         << "\n2.Remover no na arvore"
         << "\n3.Listar todos os nos da arvore"
         << "\n4.Buscar no"
         << "\n5.Somar no"
         << "\n0.Sair"
         << "\nDigite um opcao: ";
    cin >> opcao;
    return opcao;
}