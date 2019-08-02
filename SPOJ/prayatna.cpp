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

ll n,e,ans;
bool visited[N];
vector<ll> adj[N];

void init(ll n){
  fr(i,0,n){
    visited[i]=false;
    adj[i].clear();
  }
}

void dfs(ll  v){
  visited[v]=true;

  ll u;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(visited[u]) continue;
    dfs(u);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll u,v;
  while(t--){
    cin>>n>>e;

    init(n);

    fr(i,0,e){
      cin>>u>>v;
      adj[u].PB(v);
      adj[v].PB(u);
    }

    ans=0;
    fr(i,0,n){
      if(visited[i]) continue;
      ans++;
      dfs(i);
    }
    cout<<ans<<"\n";
  }

  return 0;
}
