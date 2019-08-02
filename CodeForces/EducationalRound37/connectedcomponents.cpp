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
#define N 200001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
set<ll> not_visited;
set<ll> adj[N];
ll component[N];
ll total_cmp;

void dfs(ll v){
  not_visited.erase(v);
  component[total_cmp]++;

  set<ll>::iterator itr;
  ll u=0;

  while(1){
    itr=not_visited.lower_bound(u);
    if(itr==not_visited.end()) break;
    u=(*itr);
    if(adj[v].count(u)){
      u++;
      continue;
    }
    dfs(u);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  ll x,y;
  fr(i,0,m){
    cin>>x>>y;
    adj[x].insert(y);
    adj[y].insert(x);
  }

  fr(i,1,n+1) not_visited.insert(i);
  MS(component,0);
  total_cmp=0;
  fr(i,1,n+1){
    if(not_visited.count(i)){
      total_cmp++;
      dfs(i);
    }
  }

  sort(component+1,component+1+total_cmp);
  cout<<total_cmp<<"\n";
  fr(i,1,total_cmp+1) cout<<component[i]<<" ";

  return 0;
}
