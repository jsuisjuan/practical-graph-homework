#ifndef GRAFO_LISTA_ADJACENCIA_H
#define GRAFO_LISTA_ADJACENCIA_H
#include <list>
#include <vector>

/*
    bfs = 2;
    dfs = 2;
    kruskal = 3;
*/

class Aresta {
private:
    int vertice1, vertice2, peso;
public:
    Aresta(int v1, int v2, int peso);
    int obter_vertice1();
    int obter_vertice2();
    int obter_peso();
    bool operator < (const Aresta& aresta2) const;
};

class ListaAdjacencia {
private:
    int V;
    std::list<int> *adj;
    std::vector<Aresta> arestas;
public:
    Grafo(int V);
    void adicionar_aresta(int v1, int v2);
    void adicionar_aresta(int v1, int v2, int peso);
    int obter_grau_de_saida(int v);
    bool existe_vizinho(int v1, int v2);
    void dfs(int v);
    void bfs(int v);
    void unir(int subset[], int v1, int v2);
    void buscar(int subset[], int i);
    void kruskal();
};

#endif