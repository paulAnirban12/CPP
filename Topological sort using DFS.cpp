#include <bits/stdc++.h>
#define white 0
#define yellow 1
#define black 2


using namespace std;

int nVertex, nEdge, dfsTime, adjMat[100][100], color[100], discoveryTime[100], finishingime[100];
stack<int>S ;
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
    }
    return;
}

void DFS_visit(int u)
{
    color[u] = yellow;
    dfsTime++;
    discoveryTime[u] = dfsTime;
    for(int v=0; v<nVertex; v++)
    {
        if(adjMat[u][v]==1)
        {
            if(color[v]==white)
            {
                DFS_visit(v);
            }
        }
    }
    color[u] = black;
    dfsTime++;
    finishingime[u] = dfsTime;
    S.push(u);
    return;
}

void DFS()
{
    for(int u=0; u<nVertex; u++)
    {
        color[u] = white;
    }
    dfsTime = 0;
    for(int u=0; u<nVertex; u++)
    {
        if(color[u]==white)
        {
            DFS_visit(u);
        }
    }
    return;
}

int main()
{

    inputGraph();
    DFS();
    while(!S.empty())
    {
        int x = S.top();
        cout<<x<< " " ;
        S.pop();
    }
    return 0;
}

