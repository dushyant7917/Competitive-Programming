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
#define N 150001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
vector<ll> adj[N];
bool visited[N];
bool flag=true;
ll nodes,edges;

void dfs(ll v){
  visited[v]=true;
  nodes++;
  edges+=SZ(adj[v]);

  fr(i,0,SZ(adj[v])){
    if(!visited[adj[v][i]]){
      dfs(adj[v][i]);
    }
  }
}

void solve(){
  fr(i,1,n+1){
    if(!visited[i]){
      nodes=edges=0;
      dfs(i);
    }
    if(edges!=nodes*(nodes-1)) flag=false;
  }

  if(flag) cout<<"YES";
  else cout<<"NO";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  ll a,b;
  fr(i,0,m){
    cin>>a>>b;
    adj[a].PB(b);
    adj[b].PB(a);
  }

  solve();

  return 0;
}
