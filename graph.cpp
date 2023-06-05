#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include "./header-files/graph.h"

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

int Aresta::obter_peso(){
    return peso;
}

bool Aresta::operator < (const Aresta& aresta2) const {
    return (peso < aresta2.peso);
}

Grafo::Grafo(int V) {
    this->V = V;
    adj = new std::list<int>[V];
}

void Grafo::adicionar_aresta(int v1, int v2) {
    adj[v1].push_back(v2);
}

void Grafo::adicionar_aresta(int v1, int v2, int peso) {
    Aresta aresta(v1, v2, peso);
    arestas.push_back(aresta);
}

int Grafo::obter_grau_de_saida(int v) {
    return adj[v].size();
}

bool Grafo::existe_vizinho(int v1, int v2) {
    if (find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end()) {
        return true;
    }
    return false;
}

void Grafo::dfs(int v) {
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

void Grafo::bfs(int v) {
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