#include <iostream>
#include <stdio.h>
#include <fstream>
#include <list>
#include <string>
#include <array>
#include <cctype>
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

const char *tipo_grafo;
const char *arquivo_lida_atual;
double numero_vertice_total;
int numero_arestas;

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

void  application();
int  ler_arquivo_entrada();
void representar_grafo();
void manipular_grafo_matriz();
void manipular_grafo_lista();
double concatenar_array(char arr[]);
int compara (const void * a, const void * b);

int main(int argc, char *argv[]) {
    ler_arquivo_entrada();
    std::cout<<"dados lidos e armazenados com sucesso!\n"<<std::endl;
    application();
    return 0;
}

void application() {
    representar_grafo();
    if (tipo_grafo == "matriz_adjacencia") {
        manipular_grafo_matriz();
    }
    if (tipo_grafo == "lista_adjacencia") {
        manipular_grafo_lista();
    }
}

double concatenar_array(char arr[]){
    const char *dest="";
    std::string::size_type sz; 
    return std::stod(std::strcat(arr, dest),&sz);
}

int ler_arquivo_entrada() {
    FILE *arquivo;
    const char *nome_arquivo;
    int valores[3];
    //utilizar o fstream ao inves dessa merda de fopen
    std::cout<<"GraphLib shell version: 1.0.0\n";
    std::cout<<"path (src//arq.txt): ";
    //getline(std::cin, nome_arquivo);
    
    arquivo = fopen("otherteste.txt","r");
    arquivo_lida_atual = "teste.txt";
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

int compara (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void representar_grafo() {
    double numero_vertice, valores[2];
    int contador = 0;
    std::cout<<std::endl;
    std::cout<<"1.matriz de adjacencia\n";
    std::cout<<"2.lista de adjacencia\n";
    std::cout<<"escolha um tipo de representacao: ";
    std::cin>> grafo_selecionado;
    if (grafo_selecionado == 1) {
        tipo_grafo = "matriz_adjacencia";
        std::cout<<"grafo matrix foi representado"<<std::endl;
    }
    if (grafo_selecionado == 2) {
        bool numero_vertice_alocado = false;
        tipo_grafo = "lista_adjacencia";
        numero_arestas = 0;
        for (int i = 0; i < _msize(memoria); i++) {
            char numero[10];
            int quantidade_decimais = 0; //talvez eu tenho que colocar uma condicao para n pegar o ' '
            while (memoria[i] != ' ' && memoria[i] != '\n') {
                numero[quantidade_decimais] = memoria[i];
                quantidade_decimais++;
                i++;
            }
            if (strlen(numero) != 0) {
                numero_vertice = concatenar_array(numero);
                if (numero_vertice_alocado) {
                    if (contador < 2) {
                        valores[contador] = numero_vertice;
                        contador++;
                    } if (contador == 2) {
                        std::cout<<valores[0]<<" "<<valores[1]<<std::endl;
                        grafo_lista.adicionar_aresta(valores[0], valores[1]);
                        numero_arestas++;
                        contador = 0;
                        valores[contador] = numero_vertice;
                    }
                } else {
                    numero_vertice_total = numero_vertice;
                    grafo_lista.Grafo(numero_vertice);
                    numero_vertice_alocado = true;
                }
            }
            std::fill(std::begin(numero), std::end(numero), '\0');
        }
    } else std::cout<<"nenhuma das opcoes foram escolhidas"<<std::endl;
    grafo_definido = true;
}

void manipular_grafo_matriz() {
    int opcao, vertice;
    do {
        std::cout<<"\n\t\t\t[lendo arquivo atual: ./"<<arquivo_lida_atual<<"]\n";
        std::cout<<"\t\t\t[representacao: "<<tipo_grafo<<"]\n";
        std::cout<<"\nEscolha uma opcao:\n";
        std::cout<<"\n1.imprimir saidas";
        std::cout<<"\n2.executar bfs";
        std::cout<<"\n3.executar dfs";
        std::cout<<"\n4.executar kruskal";
        std::cout<<"\n5.alterar representacao";
        std::cout<<"\n0.sair";
        std::cout<<"\nopcao selecionada: ";
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
            application(); 
            break;
        }
    } while(opcao != 0);
    free(memoria);
}

void manipular_grafo_lista() {
    int opcao, vertice;
    do {
        std::cout<<"\n\t\t\t[lendo arquivo atual: ./"<<arquivo_lida_atual<<"]\n";
        std::cout<<"\t\t\t[representacao: "<<tipo_grafo<<"]\n";
        std::cout<<"\nEscolha uma opcao:\n";
        std::cout<<"\n1.imprimir saidas";
        std::cout<<"\n2.executar bfs";
        std::cout<<"\n3.executar dfs";
        std::cout<<"\n4.executar kruskal";
        std::cout<<"\n5.alterar representacao";
        std::cout<<"\n0.sair";
        std::cout<<"\nopcao selecionada: ";
        std::cin>>opcao;
        switch(opcao){
        case 1: 
            grafo_lista.imprimir_valores(numero_vertice_total, numero_arestas, grafo_lista); 
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
    free(memoria);
}