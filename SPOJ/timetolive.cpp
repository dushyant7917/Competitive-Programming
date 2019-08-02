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
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
ll dist[N];
bool visited[N];
vector<ll> adj[N];

void init(ll n){
  fr(i,0,n){
    dist[i]=0;
    visited[i]=false;
  }
}

void dfs(ll v,ll d){
  visited[v]=true;
  dist[v]=d;

  ll u;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(visited[u]) continue;
    dfs(u,d+1);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll u,v,x,diametre;
  while(t--){
    cin>>n;

    fr(i,0,n) adj[i].clear();

    fr(i,0,n-1){
      cin>>u>>v;
      adj[u].PB(v);
      adj[v].PB(u);
    }

    init(n);

    dfs(0,0);
    x=0;
    fr(i,1,n) if(dist[i]>dist[x]) x=i;

    init(n);
    dfs(x,0);
    diametre=0;
    fr(i,0,n) diametre=max(diametre,dist[i]);
    if(diametre&1) cout<<(diametre+1)/2<<"\n";
    else cout<<diametre/2<<"\n";
  }

  return 0;
}
