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

ll n,m,src,dst;
ll dist[N],mark[501][501];
vector<pii> adj[N];
vector<ll> avoid[N];

void init(){
  fr(i,0,n){
    adj[i].clear();
    avoid[i].clear();
  }
}

void marking(){
  fr(i,0,n) fr(j,0,n) mark[i][j]=0;

  queue<ll> q;
  q.push(dst);

  ll u,v;
  while(SZ(q)){
    u=q.front();
    q.pop();
    fr(i,0,SZ(avoid[u])){
      v=avoid[u][i];
      mark[v][u]=1;
      q.push(v);
    }
  }
}

void shortest(){
  fr(i,0,n) dist[i]=INF;
  priority_queue<pii,vector<pii>,greater<pii> > pq;
  pq.push(MP(0,src));
  dist[src]=0;

  ll u,v,w;
  while(SZ(pq)){
    u=pq.top().se;
    pq.pop();

    fr(i,0,SZ(adj[u])){
      v=adj[u][i].se;
      w=adj[u][i].fi;

      if(dist[u]+w==dist[v]) avoid[v].PB(u);
      if(dist[u]+w<dist[v]){
        dist[v]=dist[u]+w;
        pq.push(MP(dist[v],v));
        avoid[v].clear();
        avoid[v].PB(u);
      }
    }
  }
}

void almostShortest(){
  fr(i,0,n) dist[i]=INF;
  priority_queue<pii,vector<pii>,greater<pii> > pq;
  pq.push(MP(0,src));
  dist[src]=0;

  ll u,v,w;
  while(SZ(pq)){
    u=pq.top().se;
    pq.pop();

    fr(i,0,SZ(adj[u])){
      v=adj[u][i].se;
      w=adj[u][i].fi;

      if(!mark[u][v] && dist[u]+w<dist[v]){
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

  while(1){
    cin>>n>>m;

    if(n==0 && m==0) break;

    cin>>src>>dst;

    init();

    ll u,v,w;
    fr(i,0,m){
      cin>>u>>v>>w;
      adj[u].PB(MP(w,v));
    }

    shortest();
    marking();
    almostShortest();

    if(dist[dst]!=INF) cout<<dist[dst]<<"\n";
    else cout<<-1<<"\n";
  }

  return 0;
}
