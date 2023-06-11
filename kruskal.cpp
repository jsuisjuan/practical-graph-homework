#include <iostream>
#include <vector>
#include <algorithm>    
#include <string.h>     
using namespace std;

class Aresta {
private:
    int vertice1, vertice2, peso;
public:
    Aresta(int v1, int v2, int peso) {
        vertice1 = v1;
        vertice2 = v2;
        this->peso = peso;
    }
    int obterVertice1() {
        return vertice1;
    }
    int obterVertice2() {
        return vertice2;
    }
    int obterPeso(){
        return peso;
    }

    // sobrescrita de operador "<"
    bool operator < (const Aresta& aresta2) const {
        return (peso < aresta2.peso);
    }
};

class Grafo {
private:
    int V;                  // número de vértices
    vector<Aresta> arestas; // vetor de arestas
public:
    Grafo(int V) {
        this->V = V;
    }

    // função que adiciona uma aresta
    void adicionarAresta(int v1, int v2, int peso) {
        Aresta aresta(v1, v2, peso);
        arestas.push_back(aresta);
    }

    // função que busca o subconjunto de um elemento "i"
    int buscar(int subset[], int i) {
        if (subset[i] == -1)
            return i;
        return buscar(subset, subset[i]);
    }

    // função para unir dois subconjuntos em um único subconjunto
    void unir(int subset[], int v1, int v2) {
        int v1_set = buscar(subset, v1);
        int v2_set = buscar(subset, v2);
        subset[v1_set] = v2_set;
    }

    // função que roda o algoritmo de Kruskal
    void kruskal() {
        vector<Aresta> arvore;
        int size_arestas = arestas.size();

        // ordena as arestas pelo menor peso
        sort(arestas.begin(), arestas.end());

        // aloca memória para criar "V" subconjuntos
        int* subset = new int[V];

        // inicializa todos os subconjuntos como conjuntos de um único elemento
        memset(subset, -1, sizeof(int) * V);

        for (int i = 0; i < size_arestas; i++) {
            int v1 = buscar(subset, arestas[i].obterVertice1());
            int v2 = buscar(subset, arestas[i].obterVertice2());

            if (v1 != v2) {
                // se forem diferentes é porque NÃp forma ciclo, insere no vetor
                arvore.push_back(arestas[i]);
                unir(subset, v1, v2);   // faz a união
            }
        }
        int size_arvore = arvore.size();

        // mostra as arestas selecionadas com seus respectivos pesos
        for (int i = 0; i < size_arvore; i++) {
            char v1 = 'A' + arvore[i].obterVertice1();
            char v2 = 'A' + arvore[i].obterVertice2();
            cout << "(" << v1 << ", " << v2 << ") = " << arvore[i].obterPeso() << endl;
        }
    }
};

int main() {
    Grafo g(7); // grafo

    // adiciona as arestas
    g.adicionarAresta(0, 1, 7);
    g.adicionarAresta(0, 3, 5);
    g.adicionarAresta(1, 2, 8);
    g.adicionarAresta(1, 3, 9);
    g.adicionarAresta(1, 4, 7);
    g.adicionarAresta(2, 4, 5);
    g.adicionarAresta(3, 4, 15);
    g.adicionarAresta(3, 5, 6);
    g.adicionarAresta(4, 5, 8);
    g.adicionarAresta(4, 6, 9);
    g.adicionarAresta(5, 6, 11);

    g.kruskal();    // roda o algoritmo de kruskal
    
    return 0;
}