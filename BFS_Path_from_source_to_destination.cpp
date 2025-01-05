#include<bits/stdc++.h>
#define infinity 999999
#define white 0
#define grey 1
#define black 2

using namespace std;

    int Edges, Vertex, i , p, q ;
    queue <int> Q ;
    int adj[1000][1000] ;
    int color[1000], Distance[1000], parent[1000], path[1000] ;
    void inputGraph()
    {
        cout << "Enter Vertex : " ;
        cin >> Vertex ;
        cout << "Enter Number Of Edges : " ;
        cin >> Edges ;
        cout << "Enter Edges " << endl ;
        for(i = 0 ; i < Edges ; i++)
        {
            cin >> p >> q ;
            adj[p][q] = 1 ;
        }
    }

    void BFS(int source,int destination)

    {
        for(i = 0 ; i < Vertex ; i++)
        {
            Distance[i] = infinity ;
            color[i] = white ;
        }
        color[source] = grey ;
        Distance[source] = 0 ;
        parent[source] = -1 ;
        Q.push(source) ;
        while(!Q.empty())
        {
            int u , v ;
            u = Q.front();
            Q.pop();
            for(v = u ; v < Vertex ; v++)
            {
                if(adj[u][v] == 1)
                {
                    if(color[v] == white)
                    {
                        color[v] = grey ;
                        Distance[v] = Distance[u]+1 ;
                        parent[v] = u ;
                        Q.push(v);
                    }
                }
            }
            color[u] = black ;
        }
        cout << "Path from source to destination =  " ;
        int node = destination ;
        int Count = 1 ;
        while(node != -1)
        {
            path[Count] = node ;
            Count++ ;
            node = parent[node];
        }
        for(i = Count ; i > 0 ; i--)
        {
            if(path[i] != path[i-1])
            {
                cout << path[i] ;
            }
        }
    }

    int main()

    {
        int source , destination;
        inputGraph();
        cout << "Source Node : " ;
        cin >> source ;
        cout << "Destination Node : " ;
        cin >> destination ;
        BFS(source,destination);
        return 0 ;
    }
