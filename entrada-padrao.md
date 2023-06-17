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
# dijkstra
    Grafo g(5);

    g.addAresta(0, 1, 4);
    g.addAresta(0, 2, 2);
    g.addAresta(0, 3, 5);
    g.addAresta(0, 1, 4);
    g.addAresta(1, 4, 1);
    g.addAresta(2, 1, 1);
    g.addAresta(2, 3, 2);
    g.addAresta(2, 4, 1);
    g.addAresta(3, 4, 1);

    cout << g.dijkstra(0, 4) << endl;

<!-- void manipular_grafo_matriz() {
    int opcao, vertice;
    do {
        std::cout<<"\t\t[grafo: "<<tipo_grafo[grafo_selecionado]<<"]";
        std::cout<<"\n1.imprimir saidas";
        std::cout<<"\n2.executar bfs";
        std::cout<<"\n3.executar dfs";
        std::cout<<"\n4.executar kruskal";
        std::cout<<"\n5.alterar representacao";
        std::cout<<"\n0.sair";
        std::cout<<"\ndigite um opcao: ";
        std::cin>>opcao;
        switch(opcao){
        case 1: 
            grafo_matriz.imprimir_valores(); 
            break;
        case 2: 
            std::cout<<"entre com um vertice inicial: ";
            std::cin>>vertice;
            grafo_matriz.bfs(vertice); 
            break;
        case 3: 
            std::cout<<"entre com um vertice inicial: ";
            std::cin>>vertice;
            std::vector<bool> visited(v, false);
            grafo_matriz.dfs(vertice, visited); 
            break;
        case 4: 
            std::cout<<"entre com um vertice inicial: ";
            std::cin>>vertice;
            grafo_matriz.kruskal(vertice); 
            break;
        case 5: 
            application(); 
            break;
        }
    } while(opcao != 0);
} -->