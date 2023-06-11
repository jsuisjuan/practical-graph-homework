#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#include "./header/grafo-matriz-adjacencia.h"
#define V 5

int parent[V];
vector<vector<int> > adj;

bool tem_ligacao(int v1,int v2) {
    if(grafo[v1][v2])return true;
    return false;
}

MatrizAdjacencia::Grafo(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new bool*[numVertices];
    for (int i = 0; i < numVertices; i++) {
      adjMatrix[i] = new bool[numVertices];
      for (int j = 0; j < numVertices; j++)
        adjMatrix[i][j] = false;
    }
}

void MatrizAdjacencia::adicionar_aresta(int i, int j) {
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
}

void MatrizAdjacencia::remover_aresta(int i, int j) {
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
}

void MatrizAdjacencia::imprimir_representacao() {
    for (int i = 0; i < numVertices; i++) {
      cout << i << " : ";
      for (int j = 0; j < numVertices; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
}

MatrizAdjacencia::~Graph() {
    for (int i = 0; i < numVertices; i++)
      delete[] adjMatrix[i];
    delete[] adjMatrix;
}

void MatrizAdjacencia::bfs(int start) {
    // Visited vector to so that
    // a vertex is not visited more than once
    // Initializing the vector to false as no
    // vertex is visited at the beginning
    vector<bool> visited(adj.size(), false);
    vector<int> q;
    q.push_back(start);
  
    // Set source as visited
    visited[start] = true;
  
    int vis;
    while (!q.empty()) {
        vis = q[0];
  
        // Print the current node
        cout << vis << " ";
        q.erase(q.begin());
  
        // For every adjacent vertex to the current vertex
        for (int i = 0; i < adj[vis].size(); i++) {
            if (adj[vis][i] == 1 && (!visited[i])) {
  
                // Push the adjacent node to the queue
                q.push_back(i);
  
                // Set
                visited[i] = true;
            }
        }
    }
}

void MatrizAdjacencia::dfs(int start, vector<bool>& visited) {
 
    // Print the current node
    cout << start << " ";
 
    // Set current node as visited
    visited[start] = true;
 
    // For every node of the graph
    for (int i = 0; i < adj[start].size(); i++) {
 
        // If some node is adjacent to the current node
        // and it has not already been visited
        if (adj[start][i] == 1 && (!visited[i])) {
            dfs(i, visited);
        }
    }
}
 
int MatrizAdjacencia::buscar(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}
 
void MatrizAdjacencia::unir(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
 
void MatrizAdjacencia::kruskal(int cost[][V]){
    int mincost = 0; // Cost of min MST.
 
    // Initialize sets of disjoint sets.
    for (int i = 0; i < V; i++)
        parent[i] = i;
 
    // Include minimum weight edges one by one
    int edge_count = 0;
    while (edge_count < V - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
 
        union1(a, b);
        printf("Edge %d:(%d, %d) cost:%d \n",
               edge_count++, a, b, min);
        mincost += min;
    }
    printf("\n Minimum cost= %d \n", mincost);
}