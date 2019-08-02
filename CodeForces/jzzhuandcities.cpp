#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m,k;
vector<pii> adj[N];
bool visited[N];
ll dist[N];
priority_queue<pii,vector<pii>,greater<pii> > pq;
ll ans=0;

void dijkstra(ll src){
  fr(i,1,n+1) dist[i]=INF;

  dist[src]=0;
  pq.push(MP(dist[src],src));

  ll v,u,w,d;
  while(SZ(pq)){
    v=pq.top().second;
    d=pq.top().first;
    pq.pop();

    if(v<0){
      v=-v;
      if(d<dist[v]) dist[v]=d;
      else{
        ans++;
        continue;
      }
    }

    if(visited[v]) continue;

    visited[v]=true;

    fr(i,0,SZ(adj[v])){
      u=adj[v][i].second;
      w=adj[v][i].first;

      if(!visited[u] && dist[v]+w<dist[u]){
        dist[u]=dist[v]+w;
        pq.push(MP(dist[u],u));
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m>>k;

  ll u,v,w;
  fr(i,0,m){
    cin>>u>>v>>w;
    adj[u].PB(MP(w,v));
    adj[v].PB(MP(w,u));
  }

  fr(i,0,k){
    cin>>v>>w;
    pq.push(MP(w,-v));
  }

  MS(visited,false);
  dijkstra(1);

  cout<<ans;

  return 0;
}
