#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

class Grafo{
private:
    int V;
    list<int>*adj;
public:
    Grafo(int V);
    void adicionarAresta(int v1,int v2);
    void dfs(int v);
};

Grafo::Grafo(int V){
    this->V=V;
    adj=new list<int>[V];
}

void Grafo::adicionarAresta(int v1,int v2){
    adj[v1].push_back(v2);
}

void Grafo::dfs(int v){
    stack<int>pilha;
    bool visitados[V];
    for(int i=0;i<V;i++)
        visitados[i]=false;
    while(true){
        if(!visitados[v]){
            cout<<"Visitando vertice "<<v<<" ...\n";
            visitados[v]=true;
            pilha.push(v);
        }
        bool achou=false;
        list<int>::iterator it;
        for(it=adj[v].begin();it!=adj[v].end();it++){
            if(!visitados[*it]){
                achou=true;
                break;
            }
        }
        if(achou)v=*it;
        else{
            pilha.pop();
            if(pilha.empty())break;
            v=pilha.top();
        }
    }
}

int main(int argc,char *argv[]){
    int V=8;
    Grafo grafo(V);
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 2);
    grafo.adicionarAresta(1, 3);
    grafo.adicionarAresta(1, 4);
    grafo.adicionarAresta(2, 5);
    grafo.adicionarAresta(2, 6);
    grafo.adicionarAresta(6, 7);
    grafo.dfs(0);   
    return 0;
}