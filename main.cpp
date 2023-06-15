#include <iostream>
#include <stdio.h>
#include <fstream>
#include <list>
#include <map>
#include "./header/grafo-lista-adjacencia.h"
#include "./header/grafo-matriz-adjacencia.h"

#define LOWER 1024
#define UPPER 65536

bool arquivo_lido = false;
bool grafo_definido = false;
int grafo_selecionado;
char *memoria;

std::map<int, std::string> tipo_grafo {
    {1,"matriz_c_peso"},
    {2,"matriz_s_peso"},
    {3,"lista_c_peso"},
    {4,"list_s_peso"}
};

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

    fazer switch case dentro do representar grafo
    -n faz sentido ter opcoes abertas  se n tem arquivo alocado
*/

int menu();
int ler_arquivo_entrada();
void representar_grafo();

int main(int argc, char *argv[]) {
    int opcao, tipo_representacao;
    std::string nome_arquivo;
    
    do {
        opcao = menu();
        switch(opcao){
            case 1: ler_arquivo_entrada(); break;
            case 2: representar_grafo(); break;
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
    } while(opcao != 0);
    return 0;
}

int menu() {
    int opcao;
    if(arquivo_lido && grafo_definido) 
        std::cout << "\n\n\n----Menu Principal (grafo "<<tipo_grafo[grafo_selecionado]<<")----\n\n";
    else std::cout << "\n\n\n----Menu Principal----\n\n";
    std::cout<< "\n1.Arquivo de entrada";
    std::cout<< "\n2.Representacao do grafo";
    std::cout<< "\n3.Busca em grafos";
    std::cout<< "\n4.Componentes conexos";
    std::cout<< "\n0.Sair";
    std::cout<< "\nDigite um opcao: ";
    std::cin >> opcao;
    return opcao;
}

int ler_arquivo_entrada() {
    FILE *arquivo;
    const char nome_arquivo;
    int numero = 0, i = 0;
    int valores[3];

    std::cout<<"Path (src//arq.txt): ";
    std::cin>> nome_arquivo;

    arquivo=fopen(nome_arquivo,"r");
    if(arquivo==NULL){
        std::cout<<"arquivo nao abriu!"<<std::endl;
        return 1;
    }
    size_t incremento=LOWER;
    size_t alocado=incremento;
    memoria = (char*)malloc(alocado);
    size_t total=0;
    while(!feof(arquivo)&&!ferror(arquivo)){
        memoria[total] = fgetc(arquivo);
        total++;
        if(total >= alocado){
            if(incremento>=UPPER) incremento=UPPER;
            alocado+=incremento;
            memoria = (char*)realloc(memoria,alocado);
            incremento*=2;
        }
    }
    if(ferror(arquivo)){
        std::cout<<"houve um erro lendo o arquivo"<<std::endl;
        return 1;
    }
    memoria = (char*)realloc(memoria,total);
    memoria[total-1]='\0';
    fclose(arquivo);
    std::cout<<"File contents:\n\n";
    std::cout<<memoria[0];
    free(memoria);
    arquivo_lido = true;
    return 0;

    

   /* ListaAdjacencia grafo;
    while (fscanf(arquivo, "%d,", &numero) > 0) {
        if (i < 3) valores[i] = numero;
        else {
            grafo.adicionar_aresta(valores[0], valores[1], valores[2]);
            i = 0;
            valores[i] = numero;
        }
        i++;
    }
    fclose(arquivo);
    return 0; */
}

void representar_grafo() {
    std::cout<<"1.Matriz de Adjacencia com peso\n";
    std::cout<<"2.Matriz de Adjacencia sem peso\n";
    std::cout<<"3.Lista de Adjacencia com peso\n";
    std::cout<<"4.Lista de Adjacencia sem peso\n";
    std::cin>> grafo_selecionado;
    if(grafo_selecionado == 1 || grafo_selecionado == 2) MatrizAdjacencia.grafo(nome_arquivo);
    else if(grafo_selecionado == 3 || grafo_selecionado == 4) ListaAdjacencia.grafo(nome_arquivo);
    else std::cout<<"nenhuma das opcoes foram escolhidas"<<std::endl;
    grafo_definido = true;
}