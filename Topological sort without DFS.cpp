#include <bits/stdc++.h>
#define white 0


using namespace std;

int nVertex, nEdge, visited = 0 ,i, indegree[100];
    int edge[100][100] ;
    stack<int>S ;
    queue<int>q ;
    queue<int>Q ;

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
        edge[p][q] = 1;
        indegree[q]++ ;
    }
    return;
}

int Topological_Sort()

{

    for(i = 0 ; i < nVertex ; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        visited++ ;
        for(int y = 0 ; y < nVertex ; y++)
        {
            if(edge[x][y] == 1)
            {
                indegree[y]-- ;
                if(indegree[y]==0)
                q.push(y);
            }
        }
        Q.push(x);
    }
    if(visited == nVertex)
        return 1 ;
    else
        return 0 ;
}



int main()
{

    inputGraph();
    int result = Topological_Sort();
    if(result == 0)
        cout<< " Topological Sort is Impossible" ;
    else
    {
        while(!Q.empty())
        {
            int u = Q.front();
            cout<< u << " " ;
            Q.pop();
        }
    }
    return 0;
}




