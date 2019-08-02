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

ll n,q;
ll a[100001]; // salary

void dfs(vector<ll> graph[], ll node, ll inc){
  ll visited[n+1]={0};
  stack<ll> s;
  s.push(node);
  visited[node] = 1;

  int cur_node;
  while(!s.empty()){
    cur_node = s.top();
    s.pop();
    a[cur_node]+=inc;
    for(ll i = 0; i<graph[cur_node].size(); i++){
      if(visited[graph[cur_node][i]] == 0){
        visited[graph[cur_node][i]] = 1;
        s.push(graph[cur_node][i]);
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>q;

  vector<ll> graph[n+1];

  fr(i,1,n+1){
    cin>>a[i];
  }

  ll u,v;
  fr(i,0,n-1){
    cin>>u>>v;
    graph[u].PB(v);
  }

  ll s,e,m;
  fr(i,0,q){
    cin>>s;
    if(s==0){
      cin>>e>>m;
      dfs(graph,e,m);
    }
    else{
      cin>>e;
      cout<<a[e]<<"\n";
    }
  }

  return 0;
}
