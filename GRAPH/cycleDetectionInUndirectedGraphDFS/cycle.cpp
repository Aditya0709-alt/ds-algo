#include <iostream>
#include <list>
using namespace std;

class graph
{
    int v;
    list<int> *adj;

public:
    graph(int v);
    void addEdge(int v, int w);
    bool checkCycle(int v, bool visited[], int parent);
    bool detectCycle();

    graph::graph(int v)
    {
        this->v = v;
        adj = new list<int>[v];
    }

    void graph::addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    bool graph::checkCycle(int v, bool visited[], int parent)
    {
        visited[v] = true;

        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if (!visited[*i])
            {
                if (checkCycle(*i, visited, v))
                {
                    return true;
                }
            }

            else if (*i != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool graph::detectCycle()
    {
        bool *visited = new bool[v];
        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
        }

        for (int u = 0; u < v; u++)
        {
            if (checkCycle(u, visited, -1))
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    if (g.detectCycle())
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is not detected" << endl;
    }
    return 0;
}