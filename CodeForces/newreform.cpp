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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
bool visited[N];
vector<ll> adj[N];
ll nodes,edges;

void dfs(ll v){
  visited[v]=true;
  nodes++;
  edges+=SZ(adj[v]);

  ll u;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(!visited[u]) dfs(u);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  ll u,v;
  fr(i,0,m){
    cin>>u>>v;
    adj[u].PB(v);
    adj[v].PB(u);
  }

  MS(visited,false);
  ll ans=0;

  fr(i,1,n+1){
    if(!visited[i]){
      edges=nodes=0;
      dfs(i);
      edges/=2;
      if(edges<nodes) ans++;
    }
  }

  cout<<ans;

  return 0;
}
