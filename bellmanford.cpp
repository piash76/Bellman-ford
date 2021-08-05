
///https://www.youtube.com/watch?v=FtN3BYH2Zes&t=55s
///https://stackoverflow.com/questions/49263065/why-need-node-number-1-iterations-in-bellman-ford-algorithm-to-find-shortest


#include <bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int w;


};

vector<node>g;

int n,m;

int dis[100005];

void ini()
{
    for(int i=0;i<=n;i++)
        dis[i]=INT_MAX;
}
void belmanford(int src)
{
    dis[src] = 0;

    for (int i = 1;i <=n - 1; ++i)
    {
        for (int j = 0; j <m; ++j)
        {
            int U=g[j].u;
            int V=g[j].v;
            int cst=g[j].w;

            if (dis[U] +cst < dis[V])
            {
                dis[V]=dis[U]+cst;
            }

        }

    }


}
bool negetive_cycle()
{
     for ( int j = 0; j <m; j++ )
     {
           int U=g[j].u;
            int V=g[j].v;
            int cst=g[j].w;

            if (dis[U] +cst < dis[V])
            {
                return true;
            }
     }

    return false;
}


int main()
{


        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            node gp;
            gp.u=u;
            gp.v=v;
            gp.w=w;
            g.push_back(gp);

        }


        belmanford(0);
        if(!negetive_cycle())
            cout<<"not possible"<<endl;
        else
            cout<<"possible"<<endl;



    return 0;
}
