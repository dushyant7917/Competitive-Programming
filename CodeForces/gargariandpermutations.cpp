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
#define N 1001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

vector<ll> adj[N];
bool visited[N];
ll ans=1;
ll depth[N];

void dfs(ll v){
  visited[v]=true;
  depth[v]=1;

  ll u;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(!visited[u]) dfs(u);
    depth[v]=max(depth[v],1+depth[u]);
  }

  ans=max(ans,depth[v]);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,k;
  cin>>n>>k;
  ll a[k+1][n+1],pos[k+1][1001];

  ll x;
  fr(i,1,k+1){
    fr(j,1,n+1){
      cin>>a[i][j];
      pos[i][a[i][j]]=j;
    }
  }

  ll cnt;
  fr(u,1,n+1){
    fr(v,1,n+1){
      if(u==v) continue;
      cnt=0;
      fr(i,1,k+1){
        if(pos[i][u]>pos[i][v]) cnt++;
      }
      if(cnt==k) adj[v].PB(u);
    }
  }

  MS(visited,false);
  fr(i,1,n+1){
    if(visited[i]) continue;
    dfs(i);
  }
  cout<<ans;

  return 0;
}
