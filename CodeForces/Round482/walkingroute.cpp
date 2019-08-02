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
#define INF 2e10
#define N 300005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,x,y;
vector<ll> adj[N];
bool found,visited[N];
ll cnt;

void dfs(ll v,ll Q){
  visited[v]=true;
  if(v==Q) found=true;
  if(found) cnt++;

  ll u;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(visited[u]) continue;
    dfs(u,Q);
  }

  if(v==Q) found=false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>x>>y;

  ll u,v,T,B;

  fr(i,0,n-1){
    cin>>u>>v;
    adj[u].PB(v);
    adj[v].PB(u);
  }

  fr(i,1,n+1) visited[i]=false;
  found=false;
  cnt=0;
  dfs(x,y);
  B=cnt;

  fr(i,1,n+1) visited[i]=false;
  found=false;
  cnt=0;
  dfs(y,x);
  T=cnt;

  cout<<(n*(n-1))-(T*B);

  return 0;
}
