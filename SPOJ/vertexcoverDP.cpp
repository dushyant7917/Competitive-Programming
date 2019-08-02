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
vector<ll> adj[N];
bool visited[N];
ll dp[N][2];

void init(){
  fr(i,1,n+1){
    visited[i]=false;
  }
}

void dfs(ll v){
  visited[v]=true;

  dp[v][1]=1;
  dp[v][0]=0;

  ll u;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(visited[u]) continue;
    dfs(u);
    dp[v][1]+=min(dp[u][1],dp[u][0]);
    dp[v][0]+=dp[u][1];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;

  ll u,v;

  fr(i,0,n-1){
    cin>>u>>v;
    adj[u].PB(v);
    adj[v].PB(u);
  }

  init();
  dfs(1);
  cout<<max(1ll,min(dp[1][0],dp[1][1]));

  return 0;
}
