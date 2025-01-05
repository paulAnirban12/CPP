#include <bits/stdc++.h>
#define infinity 999999999
#define white 0
#define grey 1
#define black 2

using namespace std;

int nVertex, nEdge, adjMat[100][100], color[100], d[100], parent[100];

void inputGraph()
{
    cout<<"Enter total number of vertices: ";
    cin>>nVertex;
    cout<<"Enter total number of edges: ";
    cin>>nEdge;
    cout<<"Enter edge: ";
    for(int i=0; i<nEdge; i++)
    {
        int p, q;
        cin>>p>>q;
        adjMat[p][q] = 1;
        adjMat[q][p] = 1; ///for undirected graph
    }
    return;
}

void BFS(int source)
{
    for(int i=0; i<nVertex; i++)
    {
        d[i] = infinity;
        color[i] = white;
    }
    color[source] = grey;
    d[source] = 0;
    parent[source] = -1;
    queue <int> Q;
    Q.push(source);

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int v=0; v<nVertex; v++)
        {
            if(adjMat[u][v]==1)
            {
                if(color[v]==white)
                {
                    color[v] = grey;
                    d[v] = d[u]+1;
                    parent[v] = u;
                    Q.push(v);
                }
            }
        }
        color[u] = black;
    }
    return;
}

int main()
{
    int source;
    inputGraph();
    cout<<"Enter the source vertex: ";
    cin>>source;
    BFS(source);

    for(int i=0; i<nVertex; i++)
    {
        cout<<"Distance of "<<i<<" from source is: "<<d[i]<<endl;
    }

    return 0;
}



