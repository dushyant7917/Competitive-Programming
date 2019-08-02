#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 0x7fffffff
#define N 200009
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
vector<pii> adj[N];
ll dist[N];
bool visited[N];

void dijkstra(){
  priority_queue<pii,vector<pii>,greater<pii> > pq;

  fr(i,1,n+1){
    pq.push(pii(dist[i],i));
  }

  ll u,v,w;
  while(!pq.empty()){
    u=pq.top().second; // current node
    pq.pop();

    fr(i,0,SZ(adj[u])){
      v=adj[u][i].second; // neighbour node
      w=adj[u][i].first; // edge weight

      if(!visited[v] && dist[u]+2*w<dist[v]){
        dist[v]=dist[u]+2*w;
        pq.push(MP(dist[v],v));
      }
    }

    visited[u]=true;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  ll x,y,w;
  fr(i,0,m){
    cin>>x>>y>>w;
    adj[x].PB(MP(w,y));
    adj[y].PB(MP(w,x));
  }

  fr(i,1,n+1) cin>>dist[i];

  dijkstra();

  fr(i,1,n+1) cout<<dist[i]<<" ";

  return 0;
}
