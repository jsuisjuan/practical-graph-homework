#ifndef GRAFO_MATRIZ_ADJACENCIA_H
#define GRAFO_MATRIZ_ADJACENCIA_H
#include <vector>

class MatrizAdjacencia {
private:
    bool** grafo;
    int V;
public:
    Grafo(int V);
    void adicionar_aresta(int i, int j);
    void remover_aresta(int i, int j);
    void imprimir_representacao();
    void bfs(int start);
    void dfs(int start, vector<bool>& visited);
    int  buscar(int i);
    void unir(int i, int j);
    void kruskal(int cost[][V]);
    ~Graph();
};

#endif