

#include<bits/stdc++.h>
#define ll long long
#define pll  pair<ll,ll>

using namespace std;

const ll inf=1e15;
const int N=10005;


struct node
{
    ll u,v,w;
};

ll a[N],vis[N],dis[N];
vector<node> g;


int main()
{

    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

    ///we will try to get the maximum, as in bellman ford we can find out minimum cost
    ///by inverting the cost value (negative) we can can find minimum cost or lowest value which
    /// is actually identical to getting max cost
    ///if positive (here negative) cycle found we can infinitely go lowest value so ans is inf
    ///if negative cycle (here positive ) it wont effect this algo in relaxation


    ll i,j;

    ll n,m;cin>>n>>m;

    for(i=0;i<=n;i++) dis[i]=inf;

    for(i=0;i<m;i++)
    {
        node tmp;
        ll x,y,z;cin>>x>>y>>z;
        tmp.u=x;
        tmp.v=y;
        tmp.w=-z;

        g.push_back(tmp);
    }

    dis[1]=0;

    for(i=1;i<=n-1;i++)
    {
        for(j=0;j<m;j++)
        {
            ll U=g[j].u;
            ll V=g[j].v;
            ll cst=g[j].w;

            if(dis[V]>dis[U]+cst)
            {
                dis[V]=dis[U]+cst;
            }

        }
    }

   /// /*

    ///finding negative cycle

    ///again relaxing for getting all nodes cost including negative cycle

    for(i=1;i<=n-1;i++)
    {
        for(j=0;j<m;j++)
        {
            ll U=g[j].u;
            ll V=g[j].v;
            ll cst=g[j].w;

            if(dis[V]>dis[U]+cst)
            {
                dis[V]=-inf;
            }

        }
    }



    if(dis[n]==-inf)
    {
        cout<<"inf"<<"\n";
    }
    else cout<<-dis[n]<<"\n";

    ///*/



    return 0;

}




