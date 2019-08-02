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
#define N 100009
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m,q;
string src,dst;

ll dijkstra(vector<pii> adj[],map<string,ll> mp){
  bool visited[n+1];
  ll dist[n+1];
  fr(i,0,n+1) visited[i]=false;
  fr(i,0,n+1) dist[i]=INF;

  priority_queue<pii,vector<pii>,greater<pii> > pq;

  ll x=mp[src],y=mp[dst];
  dist[x]=0;
  pq.push(MP(0,x));

  ll u,v,w;
  while(!pq.empty()){
    u=pq.top().second; // current node
    pq.pop();

    if(u==y) return dist[u];

    fr(i,0,SZ(adj[u])){
      v=adj[u][i].second; // neighbour node
      w=adj[u][i].first; // edge weight

      if(!visited[v] && dist[u]+w<dist[v]){
        dist[v]=dist[u]+w;
        pq.push(MP(dist[v],v));
      }
    }

    visited[u]=true;
  }

  return INF;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  string name;
  ll node,e,v,w;

  while(t--){
    cin>>n;
    vector<pii> adj[n+1];
    map<string,ll> mp;
    node=0;
    fr(i,0,n){
      cin>>name;
      node++;
      mp[name]=node;
      cin>>m;
      fr(i,0,m){
        cin>>v>>w;
        adj[node].PB(pii(w,v));
      }
    }

    cin>>q;
    fr(i,0,q){
      cin>>src>>dst;
      cout<<dijkstra(adj,mp)<<"\n";
    }
  }

  return 0;
}
