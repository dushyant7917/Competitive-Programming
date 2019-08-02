#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e16
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

void dijkstras(vector<pii> adj[],ll src,ll* dist){
  priority_queue<pii,vector<pii>,greater<pii> > pq;

  pq.push(MP(0,src));
  dist[src]=0;

  ll u,v,w;
  while(SZ(pq)){
    u=pq.top().se;
    pq.pop();

    fr(i,0,SZ(adj[u])){
      w=adj[u][i].fi;
      v=adj[u][i].se;

      if(dist[u]+w<dist[v]){
        dist[v]=dist[u]+w;
        pq.push(MP(dist[v],v));
      }
    }
  }

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,m,k,s,d;
  while(t--){
    cin>>n>>m>>k>>s>>d;

    vector<pii> f[n+1],b[n+1];
    ll df[n+1],db[n+1];

    fr(i,1,n+1) df[i]=db[i]=INF;

    ll u,v,w;

    fr(i,0,m){
      cin>>u>>v>>w;
      f[u].PB(MP(w,v));
      b[v].PB(MP(w,u));
    }

    dijkstras(f,s,df);
    dijkstras(b,d,db);

    ll ans=min(df[d],db[s]);

    fr(i,0,k){
      cin>>u>>v>>w;
      ans=MIN(ans,df[u]+w+db[v],df[v]+w+db[u]);
    }

    if(ans!=INF) cout<<ans<<"\n";
    else cout<<-1<<"\n";
  }

  return 0;
}
