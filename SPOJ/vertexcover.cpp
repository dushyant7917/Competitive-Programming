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
bool selected[N];

void dfs(ll v){
  visited[v]=true;

  ll u,cnt=0;

  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(visited[u]) continue;
    dfs(u);
    if(!selected[u] && !selected[v]) selected[v]=true;
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

  if(n==1) cout<<0;

  else{
    fr(i,1,n+1){
      visited[i]=selected[i]=false;
    }

    dfs(1);

    ll ans=0;
    fr(i,1,n+1) if(selected[i]) ans++;

    cout<<ans;
  }

  return 0;
}
