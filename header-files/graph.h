#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <vector>

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

class Grafo {
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
};

#endif