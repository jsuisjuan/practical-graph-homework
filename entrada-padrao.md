### entradas padrao
## lista adjacencia
# grafo
    Grafo grafo(4);
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 3);
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(3, 1);
    grafo.adicionarAresta(3, 2);
# bfs
    int V = 8;
    Grafo grafo(V);
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 2);
    grafo.adicionarAresta(1, 3);
    grafo.adicionarAresta(1, 4);
    grafo.adicionarAresta(2, 5);
    grafo.adicionarAresta(2, 6);
    grafo.adicionarAresta(6, 7);
    grafo.bfs(0);
# dfs
    int V = 8;
    Grafo grafo(V);
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 2);
    grafo.adicionarAresta(1, 3);
    grafo.adicionarAresta(1, 4);
    grafo.adicionarAresta(2, 5);
    grafo.adicionarAresta(2, 6);
    grafo.adicionarAresta(6, 7);
    grafo.dfs(0);   
# kruskal
    Grafo g(7); 
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
    g.kruskal();

## matriz adjacencia
# grafo
# dfs
    int v = 5;
    int e = 4;
    adj = vector<vector<int> >(v, vector<int>(v, 0));
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(0, 4);
    vector<bool> visited(v, false);
    dfs(0, visited);
# kruskal
    int cost[][V] = {
        { INT_MAX, 2, INT_MAX, 6, INT_MAX },
        { 2, INT_MAX, 3, 8, 5 },
        { INT_MAX, 3, INT_MAX, INT_MAX, 7 },
        { 6, 8, INT_MAX, INT_MAX, 9 },
        { INT_MAX, 5, 7, 9, INT_MAX },
    };
    kruskalMST(cost);