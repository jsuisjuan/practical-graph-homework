#ifndef GRAFO_LISTA_ADJACENCIA_H
#define GRAFO_LISTA_ADJACENCIA_H
#include <list>
#include <queue>
#include <vector>
#define INFINITO 10000000

class Aresta {
private:
    int vertice1, vertice2, peso;
public:
    Aresta(int v1, int v2, int peso);
    int  obter_vertice1();
    int  obter_vertice2();
    int  obter_peso();
    bool operator < (const Aresta& aresta2) const;
};

class ListaAdjacencia {
private:
    int V;
    std::list<int> *adj;
    std::vector<Aresta> arestas;
    std::list<std::pair<int, int> > * adjd;
public:
    void Grafo(int V);
    void adicionar_aresta(int v1, int v2);
    void adicionar_aresta(int v1, int v2, int peso);
    int  obter_grau_de_saida(int v);
    bool existe_vizinho(int v1, int v2);
    void imprimir_valores(double numero_vertice, int numero_arestas, ListaAdjacencia grafo_lista);
    void dfs(int v);
    void bfs(int v);
    void unir(int subset[], int v1, int v2);
    int buscar(int subset[], int i);
    void kruskal();
    int  dijkstra(int orig, int dest);
};

#endif