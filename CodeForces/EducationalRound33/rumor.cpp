#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll a[N];
ll visited[N]={0};
vector<ll> graph[N];
ll n,m;
ll mv;

void dfs(ll node){
  visited[node]=1;
  mv=min(mv,a[node]);

  fr(i,0,graph[node].size()){
    if(!visited[graph[node][i]]){
      dfs(graph[node][i]);
    }
  }
}

ll fn(){
  ll ans=0;

  fr(i,1,n+1){
    if(!visited[i]){
      mv=INF;
      dfs(i);
      ans+=mv;
    }
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  fr(i,1,n+1) cin>>a[i];

  ll u,v;
  fr(i,0,m){
    cin>>u>>v;
    graph[u].PB(v);
    graph[v].PB(u);
  }

  cout<<fn();

  return 0;
}
