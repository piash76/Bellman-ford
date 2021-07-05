
///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>

#define ff    first
#define ss    second

#define  mp  make_pair
#define  pb  push_back

#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int mod2=2147483647; ///2^31-1

const int N=2005;

ll dis[N];
ll n,m;
struct edge
{
    ll u,v,w;
};


vector<edge> g;

void bellman_ford(ll src)
{
    dis[src]=0;

    for(ll i=1;i<=n-1;i++)
    {
        for(ll j=0;j<m;j++)
        {
            ll U=g[j].u;
            ll V=g[j].v;
            ll cst=g[j].w;

            if(dis[U]+cst<dis[V])
            {
                dis[V]=dis[U]+cst;
            }
        }
    }
}


bool negative_cycle()
{
    for(ll i=0;i<m;i++)
    {
         ll U=g[i].u;
            ll V=g[i].v;
            ll cst=g[i].w;

            if(dis[U]+cst<dis[V])
            {
               return true;
            }

    }


    return false;
}

int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    ll t,i,j;
    cin>>t;
    while(t--)
    {

         for(i=0;i<=n;i++) dis[i]=inf;

         g.clear();

        cin>>n>>m;
        for(i=1;i<=m;i++)
        {
            ll u,v,w;cin>>u>>v>>w;
            edge e;
            e.u=u;
            e.v=v;
            e.w=w;

            g.push_back(e);


        }

        bellman_ford(0);

        if(negative_cycle()) cout<<"possible"<<endl;
        else cout<<"not possible"<<endl;




    }

    return 0;

}




