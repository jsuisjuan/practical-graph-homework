#include <iostream>
#include <stdio.h>
#include <list>
#include "./header/grafo-lista-adjacencia.h"
#include "./header/grafo-matriz-adjacencia.h"

bool arquivo_lido = false;
const char* tipo_grafo;

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
    int opcao, tipo_representacao;
    string nome_arquivo;
    
    do {
        opcao = menu();
        switch(opcao){
            case 1: 
                std::cout<<"Path (src//arq.txt): ";
                std::cin>>nome_arquivo;
                arquivo_lido = true;
                break;
            case 2: 
                std::cout<<"1.Matriz de Adjacencia com peso\n";
                std::cout<<"2.Matriz de Adjacencia sem peso\n";
                std::cout<<"3.Lista de Adjacencia com peso\n";
                std::cout<<"4.Lista de Adjacencia sem peso\n";
                tipo_grafo = "Matriz de Adjacencia com peso";
                //std::cin>>tipo_representacao;
                /* arquivo_lido = !arquivo_lido;
                if(tipo_representacao == 1) MatrizAdjacencia.grafo(nome_arquivo);
                if(tipo_representacao == 2) MatrizAdjacencia.grafo(nome_arquivo);
                if(tipo_representacao == 3) ListaAdjacencia.grafo(nome_arquivo);
                if(tipo_representacao == 4) ListaAdjacencia.grafo(nome_arquivo);
                else std::cout<<"nenhuma das opcoes foram escolhidas.\n"; */
                break;
            case 3: 
                std::cout<<"1.BFS\n";
                std::cout<<"2.DFS\n";
                /* std::cin>>tipo_representacao;
                if(tipo_representacao == 1) MatrizAdjacencia.bfs(nome_arquivo);
                if(tipo_representacao == 2) MatrizAdjacencia.dfs(nome_arquivo);
                else std::cout<<"nenhuma das opcoes foram escolhidas.\n"; */
                break;
            case 4: break;
        }
    } while(op1 != 0);
    return 0;
}

int menu() {
    int opcao;
    if(!arquivo_lido && !tipo_grafo) std::cout << "\n\n\n----Menu Principal ----\n\n";
    else std::cout << "\n\n\n----Menu Principal (grafo "<<tipo_grafo<<")----\n\n";
    std::cout<< "\n1.Arquivo de entrada";
    std::cout<< "\n2.Representacao do grafo";
    std::cout<< "\n3.Busca em grafos";
    std::cout<< "\n4.Componentes conexos";
    std::cout<< "\n0.Sair";
    std::cout<< "\nDigite um opcao: ";
    std::cin >> opcao;
    return opcao;
}

int ler_arquivo_entrada(string nome_arquivo) {
    FILE *arquivo;
    string nome_arquivo;
    int numero = 0, i = 0;
    int valores[3];

    arquivo = fopen(nome_arquivo, "r");

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
}