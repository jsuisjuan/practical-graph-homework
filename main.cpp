#include <iostream>
#include <stdio.h>
#include <fstream>
#include <list>
#include <array>
#include <bits/stdc++.h>
#include <typeinfo>
#include <malloc.h>
#include <map>
#include "./header/grafo-lista-adjacencia.h"
#include "./header/grafo-matriz-adjacencia.h"

#define LOWER 1024
#define UPPER 65536

bool arquivo_lido = false;
bool grafo_definido = false;
int grafo_selecionado;
char *memoria;

MatrizAdjacencia grafo_matriz;
ListaAdjacencia grafo_lista;

std::map<int, std::string> tipo_grafo {
    {1,"matriz_adjacencia"},
    {2,"lista_adjacencia"}
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

int  application();
int  ler_arquivo_entrada();
void representar_grafo();
void manipular_grafo_matriz();
void manipular_grafo_lista();
double concatenar_array(char arr[]);

int main(int argc, char *argv[]) {
    ler_arquivo_entrada();
    if (arquivo_lido && memoria != NULL) {
        std::cout<<"dados lidos e armazenados com sucesso!\n"<<std::endl;
        application();
    }
    return 0;
}

int application() {
    representar_grafo();
    if (tipo_grafo[grafo_selecionado] == "matriz_adjacencia") manipular_grafo_matriz();
    if (tipo_grafo[grafo_selecionado] == "lista_adjacencia") manipular_grafo_lista();
    return 0;
}

double concatenar_array(char arr[]){
    const char *dest="";
    std::string::size_type sz; 
    return std::stod(std::strcat(arr, dest),&sz);
}

int ler_arquivo_entrada() {
    FILE *arquivo;
    char *nome_arquivo;
    int valores[3];

    std::cout<<"GraphLib shell version: 1.0.0\n";
    std::cout<<"path (src//arq.txt): ";
    std::cin>>nome_arquivo;

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
    return 0;
}

void representar_grafo() {
    bool numero_vertice_alocado = false;
    double valores[2], numero_vertice;
    int contador = 0;
    std::cout<<"1.matriz de adjacencia\n";
    std::cout<<"2.lista de adjacencia\n";
    std::cout<<"escolha um tipo de representacao: ";
    std::cin>> grafo_selecionado;
    if (grafo_selecionado == 1) {
        std::cout<<"grafo matrix foi representado"<<std::endl;
    }
    if (grafo_selecionado == 2) {
        for (int i = 0; i < _msize(memoria); i++) {
            char numero[10];
            int quantidade_decimais = 0; //talvez eu tenho que colocar uma condicao para n pegar o ' '
            while (memoria[i] != ' ' && memoria[i] != '\n') {
                numero[quantidade_decimais] = memoria[i];
                quantidade_decimais++;
                i++;
            }
            std::cout<<concatenar_array(numero)<<std::endl;
            numero_vertice = concatenar_array(numero);
            if (numero_vertice_alocado) {
                if (contador < 2) valores[contador] = numero_vertice;
                else {
                    grafo_lista.adicionar_aresta(valores[0], valores[1]);
                    contador = 0;
                    valores[contador] = numero_vertice;
                }
                contador++;
            } else {
                grafo_lista.Grafo(numero_vertice);
                numero_vertice_alocado = true;
            }
            std::fill(std::begin(numero), std::end(numero), '\0');
        }
    } else std::cout<<"nenhuma das opcoes foram escolhidas"<<std::endl;
    grafo_definido = true;
}

void manipular_grafo_matriz() {
    int opcao, vertice;
    do {
        std::cout<<"\t\t[grafo: "<<tipo_grafo[grafo_selecionado]<<"]";
        std::cout<<"\n1.imprimir saidas";
        std::cout<<"\n2.executar bfs";
        std::cout<<"\n3.executar dfs";
        std::cout<<"\n4.executar kruskal";
        std::cout<<"\n5.alterar representacao";
        std::cout<<"\n0.sair";
        std::cout<<"\ndigite um opcao: ";
        std::cin>>opcao;
        switch(opcao){
        case 1: 
            std::cout<<"matriz"<<std::endl;
            break;
        case 2: 
            std::cout<<"matriz"<<std::endl;
            break;
        case 3: 
            std::cout<<"matriz"<<std::endl;
            break;
        case 4: 
            std::cout<<"matriz"<<std::endl;
            break;
        case 5: 
            std::cout<<"matriz"<<std::endl;
            break;
        }
    } while(opcao != 0);
}

void manipular_grafo_lista() {
    int opcao, vertice;
    do {
        std::cout<<"\t\t[grafo: "<<tipo_grafo[grafo_selecionado]<<"]";
        std::cout<<"\n1.imprimir saidas";
        std::cout<<"\n2.executar bfs";
        std::cout<<"\n3.executar dfs";
        std::cout<<"\n4.executar kruskal";
        std::cout<<"\n5.alterar representacao";
        std::cout<<"\n0.sair";
        std::cout<<"\ndigite um opcao: ";
        std::cin>>opcao;
        switch(opcao){
        case 1: 
            grafo_lista.imprimir_valores(); 
            break;
        case 2: 
            std::cout<<"entre com um vertice inicial: ";
            std::cin>>vertice;
            grafo_lista.bfs(vertice); 
            break;
        case 3: 
            std::cout<<"entre com um vertice inicial: ";
            std::cin>>vertice;
            grafo_lista.dfs(vertice); 
            break;
        case 4: 
            grafo_lista.kruskal(); 
            break;
        case 5: 
            application(); 
            break;
        }
    } while(opcao != 0);
}