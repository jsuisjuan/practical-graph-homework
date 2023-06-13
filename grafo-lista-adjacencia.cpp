#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include "./header/grafo-lista-adjacencia.h"

Aresta::Aresta(int v1, int v2, int peso) {
    vertice1 = v1;
    vertice2 = v2;
    this->peso = peso;
}

int Aresta::obter_vertice1() {
    return vertice1;
}

int Aresta::obter_vertice2() {
    return vertice2;
}

int Aresta::obter_peso() {
    return peso;
}

bool Aresta::operator < (const Aresta& aresta2) const {
    return (peso < aresta2.peso);
}

ListaAdjacencia::Grafo(int V) {
    this->V = V;
    adj = new std::list<int>[V];
}

void ListaAdjacencia::adicionar_aresta(int v1, int v2) {
    adj[v1].push_back(v2);
}

void ListaAdjacencia::adicionar_aresta(int v1, int v2, int peso) {
    Aresta aresta(v1, v2, peso);
    arestas.push_back(aresta);
}

int ListaAdjacencia::obter_grau_de_saida(int v) {
    return adj[v].size();
}

bool ListaAdjacencia::existe_vizinho(int v1, int v2) {
    if (find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end()) {
        return true;
    }
    return false;
}

void ListaAdjacencia::dfs(int v) {
    std::stack<int> pilha;
    bool visitados[V];
    for (int i = 0; i < V; i++) {
        visitados[i] = false;
    }
    while (true) {
        if (!visitados[v]) {
            std::cout << "Visitando vertice " << v << " ...\n";
            visitados[v] = true;
            pilha.push(v);
        }
        bool achou = false;
        std::list<int>::iterator it;
        for (it = adj[v].begin(); it != adj[v].end(); it++) {
            if (!visitados[*it]) {
                achou = true;
                break;
            }
        }
        if (achou) {
            v = *it;
        } else {
            pilha.pop();
            if (pilha.empty()) {
                break;
            }
            v = pilha.top();
        }
    }
}

void ListaAdjacencia::bfs(int v) {
    std::queue<int> fila;
    bool visitados[V];
    for (int i = 0; i < V; i++) {
        visitados[i] = false;
    }
    std::cout << "Visitando vertice " << v << " ...\n";
    visitados[v] = true;
    while (true) {
        std::list<int>::iterator it;
        for (it = adj[v].begin(); it != adj[v].end(); it++) {
            if (!visitados[*it]) {
                std::cout << "Visitando vertice " << *it << " ...\n";
                visitados[*it] = true;
                fila.push(*it);
            }
        }
        if (!fila.empty()) {
            v = fila.front();
            fila.pop();
        } else {
            break;
        }
    }
}

int ListaAdjacencia::buscar(int subset[], int i) {
    if (subset[i] == -1) {
        return i;
    }
    return buscar(subset, subset[i]);
}
    
void ListaAdjacencia::unir(int subset[], int v1, int v2) {
    int v1_set = buscar(subset, v1);
    int v2_set = buscar(subset, v2);
    subset[v1_set] = v2_set;
}

void ListaAdjacencia::kruskal() {
    vector<Aresta> arvore;
    int size_arestas = arestas.size();

    sort(arestas.begin(), arestas.end());
    int* subset = new int[V];
    memset(subset, -1, sizeof(int) * V);

    for (int i = 0; i < size_arestas; i++) {
        int v1 = buscar(subset, arestas[i].obterVertice1());
        int v2 = buscar(subset, arestas[i].obterVertice2());

        if (v1 != v2) {
            arvore.push_back(arestas[i]);
            unir(subset, v1, v2);   
        }
    }
    int size_arvore = arvore.size();

    for (int i = 0; i < size_arvore; i++) {
        char v1 = 'A' + arvore[i].obterVertice1();
        char v2 = 'A' + arvore[i].obterVertice2();
        std::cout << "(" << v1 << ", " << v2 << ") = " << arvore[i].obterPeso() << std::endl;
    }
}
