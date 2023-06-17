#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
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
    if (std::find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end()) {
        return true;
    }
    return false;
}

void ListaAdjacencia::imprimir_valores() {
    std::cout<<"imprimiu saida lista!"<<std::endl;;
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
    std::vector<Aresta> arvore;
    int size_arestas = arestas.size();

    std::sort(arestas.begin(), arestas.end());
    int* subset = new int[V];
    memset(subset, -1, sizeof(int) * V);

    for (int i = 0; i < size_arestas; i++) {
        int v1 = buscar(subset, arestas[i].obter_vertice1());
        int v2 = buscar(subset, arestas[i].obter_vertice2());

        if (v1 != v2) {
            arvore.push_back(arestas[i]);
            unir(subset, v1, v2);   
        }
    }
    int size_arvore = arvore.size();

    for (int i = 0; i < size_arvore; i++) {
        char v1 = 'A' + arvore[i].obter_vertice1();
        char v2 = 'A' + arvore[i].obter_vertice2();
        std::cout << "(" << v1 << ", " << v2 << ") = " << arvore[i].obter_peso() << std::endl;
    }
}

int ListaAdjacencia::dijkstra(int orig, int dest) {
        // vetor de distâncias
        int dist[V];

        /*
            vetor de visitados serve para caso o vértice já 
            tenha sido expandido (visitado), não expandir mais 
        */
        int visitados[V];

        std::priority_queue < std::pair<int, int>,
            std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        
        // inicia o vetor de distâncias e visitados
        for (int i = 0; i < V; i++) {
            dist[i] = INFINITO;
            visitados[i] = false;
        }

        // a distância de orig para orig é 0
        dist[orig] = 0;

        // insere na fila
        pq.push(std::make_pair(dist[orig], orig));

        // loop do algoritmo
        while(!pq.empty()) {
            std::pair<int , int> p = pq.top();   // extrai o pair do topo
            int u = p.second;               // obtém o vértice do pair
            pq.pop();                       // remove da fila

            // verifica se o vértice não foi expandido
            if (visitados[u] == false) {
                // marca como visitado
                visitados[u] = true;
                std::list<std::pair<int, int>>::iterator it;

                // percorre os vértices "v" adjacentes de "u"
                for (it = adjd[u].begin(); it != adjd[u].end(); it++) {
                    // obtém o vértice adjacente e o custo da aresta
                    int v = it->first;
                    int custo_aresta = it->second;

                    // relaxamento (u, v)
                    if (dist[v] > (dist[u] + custo_aresta)) {
                        // atualiza a distância de "v" e insere
                        dist[v] = dist[u] + custo_aresta;
                        pq.push(std::make_pair(dist[v], v));
                    }

                }
            }
        }
        // retorna a distância mínima até o destino
        return dist[dest];
}