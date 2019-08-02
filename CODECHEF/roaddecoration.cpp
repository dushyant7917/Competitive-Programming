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
#define INF 2e15
#define N 20005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))
#define pp pair<ll,pair<ll,ll> >

ll n,m;
vector<pii> adj[N];
ll lastEdge[N]; // last/lastest edge weight considered/processed for a node
ll dist[N];
ll mst,spt; // minimum spanning tree and shortest path tree costs
bool visited[N];

void init(){
  fr(i,0,n){
    adj[i].clear();
    visited[i]=false;
    dist[i]=lastEdge[i]=INF;
  }
}

void prims(){
  priority_queue<pii,vector<pii>,greater<pii> > pq;
  pq.push(pii(0,0));
  mst=0;

  ll u,v,w;
  while(SZ(pq)){
    u=pq.top().se;
    w=pq.top().fi;
    pq.pop();

    if(visited[u]) continue;

    mst+=w;
    visited[u]=true;

    fr(i,0,SZ(adj[u])){
      v=adj[u][i].se;
      if(!visited[v]) pq.push(adj[u][i]);
    }
  }
}

void dijsktras(){
  priority_queue<pp,vector<pp>,greater<pp> > pq;

  pq.push(MP(0,MP(0,0)));
  dist[0]=lastEdge[0]=0;

  ll u,v,w;
  while(SZ(pq)){
    u=pq.top().se.se;
    pq.pop();

    fr(i,0,SZ(adj[u])){
      v=adj[u][i].se;
      w=adj[u][i].fi;

      if(dist[u]+w<dist[v] || (dist[u]+w==dist[v] && w<lastEdge[v])){
        dist[v]=dist[u]+w;
        lastEdge[v]=w;
        pq.push(MP(dist[v],MP(lastEdge[v],v)));
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

  ll u,v,w;
  bool flag;
  while(t--){
    cin>>n>>m;

    init();

    fr(i,0,m){
      cin>>u>>v>>w;
      adj[u].PB(pii(w,v));
      adj[v].PB(pii(w,u));
    }

    prims();
    dijsktras();

    flag=true;
    spt=0;

    fr(i,0,n){
      if(dist[i]==INF) flag=false;
      spt+=lastEdge[i];
    }

    if(!flag || mst!=spt) cout<<"NO\n";
    else cout<<"YES\n";
  }

  return 0;
}
