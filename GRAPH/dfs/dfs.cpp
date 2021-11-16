#include <iostream>
#include <list>
using namespace std;

class graph
{
    int v;
    list<int> *adj;
    bool *visited;

public:
    graph(int v);
    void addEdge(int v, int w);
    void dfs(int s);
};

graph::graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
    visited = new bool[v];
}

void graph::addEdge(int v, int w)
{
    adj[v].push_front(w);
}

void graph::dfs(int s)
{
    visited[s] = true;
    list<int> adj1 = adj[s];

    cout << s << " ";

    list<int>::iterator i;
    for (i = adj1.begin(); i != adj1.end(); ++i)
        if (!visited[*i])
            dfs(*i);
}

int main()
{
    graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.dfs(1);
    cout << endl;
    return 0;
}