#include <iostream>
#include <stdio.h>
#include <list>
#include <algorithm>
using namespace std;


class Grafo {
private:
    int V;
    list<int> *adj;
public:
    Grafo(int V);
    void adicionarAresta(int v1, int v2);
    int obterGrauDeSaida(int v);
    bool existeVizinho(int v1, int v2);
};

Grafo::Grafo(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Grafo::adicionarAresta(int v1, int v2) {
    adj[v1].push_back(v2);
}

int Grafo::obterGrauDeSaida(int v) {
    return adj[v].size();
}

bool Grafo::existeVizinho(int v1, int v2) {
    if (find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end())
        return true;
    return false;
}

int main(int argc, char *argv[]) {
    Grafo grafo(4);

    

    FILE *arquivo;
    int numero = 0, i = 0;
    int valores[3];

    arquivo = fopen("teste.txt", "r");
    if (!arquivo) {
        printf("Arquivo nao esta abrindo.");
        return 1;
    }
    while (fscanf(arquivo, "%d,", &numero) > 0) {
        if (i < 3) valores[i] = numero;
        else {
            grafo.adicionarAresta(valores[0], valores[1]);
            i = 0;
            valores[i] = numero;
        }
        i++;
    }
    fclose(arquivo); 
    
    cout<<"Grau de saida do vertice 1: "<<grafo.obterGrauDeSaida(1)<<endl;
    cout<<"Grau de saida do vertice 3: "<<grafo.obterGrauDeSaida(3)<<endl;
    cout<<"Grau de saida do vertice 0: "<<grafo.obterGrauDeSaida(0)<<endl;
    if (grafo.existeVizinho(0, 1))cout<<"\n\n1 e vizinho de 0\n";
    else cout<<"\n\n1 NAO e vizinho de 0\n";
    if (grafo.existeVizinho(0, 2))cout<<"2 e vizinho de 0\n";
    else cout<<"2 NAO e vizinho de 0\n";
    return 0;
}
