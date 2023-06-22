#include <iostream>
#include <vector>
using namespace std;

/*
Ma trận kề (A)
Danh sách cạnh (B)
Danh sách kề (C)
*/
void transBA(int a[][100], int &n, int &m)
{
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so canh: ";
    cin >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cout <<"Nhap canh: ";
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
}

void transBC(vector<int> a[100], int &n, int &m)
{
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so canh: ";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cout <<"Nhap canh: ";
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

// Class do thi
class Graph
{
private:
    int V;
    vector<int> *adj;
public: 
    Graph(int V)
    {
        this->V = V;
        adj = new vector<int>[V];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    int getV()
    {
        return V;
    }

    vector<int> getAdj(int v) 
    {
        return adj[v];
    }

};

class GrapProcessor
{
public:
    void Processor(Graph &G)
    {
        int V = G.getV();
        for (int i = 0; i < V; i++)
        {
            vector<int> adj = G.getAdj(i);
            for (auto j = adj.begin(); j != adj.end(); ++j)
            {
                // Xu ly
            }
        }
    }
};

