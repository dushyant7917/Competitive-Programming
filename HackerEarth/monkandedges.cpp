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
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,q;
vector<ll> adj[N];
bool visited[N];
ll parent[N];
ll sz[N];

ll dfs(ll v){
  visited[v]=true;
  sz[v]=1;

  ll u;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(!visited[u]){
      parent[u]=v;
      sz[v]+=dfs(u);
    }
  }

  return sz[v];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>q;
  vector<pii> edge;
  ll a,b;
  fr(i,0,n-1){
    cin>>a>>b;
    edge.PB(pii(a,b));
    adj[a].PB(b);
    adj[b].PB(a);
  }

  MS(visited,false);
  parent[1]=-1;
  sz[1]=dfs(1);

  ll x,l,r;
  fr(i,0,q){
    cin>>x;
    a=edge[x-1].first;
    b=edge[x-1].second;
    if(parent[a]==b){
      l=sz[a];
      r=n-sz[a];
      cout<<((n*(n-1))/2)-((l*(l-1))/2)-((r*(r-1))/2)<<"\n";
    }
    else{
      l=sz[b];
      r=n-sz[b];
      cout<<((n*(n-1))/2)-((l*(l-1))/2)-((r*(r-1))/2)<<"\n";
    }
  }

  return 0;
}
