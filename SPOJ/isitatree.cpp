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
#define N 10001

ll n,m;
ll visited[N]={0};
vector<ll> graph[N];
vector<ll> tree;

void dfs(ll node){
  visited[node]=1;
  tree.PB(node);

  fr(i,0,graph[node].size()){
    if(!visited[graph[node][i]]){
      dfs(graph[node][i]);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  ll u,v;
  fr(i,0,m){
    cin>>u>>v;
    graph[u].PB(v);
    graph[v].PB(u);
  }

  dfs(1);
  if(m!=n-1){
    cout<<"NO";
  }
  else if(tree.size()!=n){
    cout<<"NO";
  }
  else{
    cout<<"YES";
  }

  return 0;
}
