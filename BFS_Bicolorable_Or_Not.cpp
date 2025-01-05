#include<bits/stdc++.h>
#define white 0
#define red 1
#define green 2
    using namespace std ;
    int edge, vertex,i , p , q , source;
    int node[100],a[100][100];
    int color[100],same;
    void inputgraph()
    {
        cout<<"Vertex : " ;
        cin >> vertex ;
        cout<<"Edges : " ;
        cin>> edge ;
        for(i = 0 ; i < vertex ; i++)
            node[i] = i ;
        for(i = 0 ; i < edge ; i++)
        {
            cin>>p>>q ;
            a[p][q] = 1 ;
            a[q][p] = 1 ;
        }
    }
    int colorcheck(int u, int v)
    {
        if(color[u]== color[v])
            return 1 ;
        else
        {
            if(color[v]== white)
            {
                if(color[u]== red)
                    color[v] = green ;
                else
                    color[v] = red ;
            }
        }
        return 0 ;
    }
    int BFS(int source)
    {
        queue<int>Q ;
        for(i = 0 ; i < vertex ; i++)
        {
            color[i] = white ;
            Q.push(i);
        }
        color[source] = red ;
        while(!Q.empty())
        {
            int u , v ;
            u = Q.front();
            Q.pop();
            for(v = 0 ; v < vertex ; v++)
            {
                if(a[u][v]==1)
                {
                    same = colorcheck(u,v);
                }
                if(same==1)
                    break ;
            }

        }
        return same ;
    }
    int main()

    {
        inputgraph();
        source = node[0] ;
        int Result = BFS(source);
        if(Result == 0)
            cout << "BICOLORABLE" ;
        else
            cout << "NOT BICOLORABLE" ;
        return 0 ;
    }
