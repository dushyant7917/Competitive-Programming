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

void dfs(ll node, ll visited[], vector<ll> graph[]) {
    visited[node] = 1;
    for(ll i = 0; i < graph[node].size(); i++)    {
        if(visited[graph[node][i]] == 0)
            dfs(graph[node][i], visited, graph);
    }
}

ll num_connections(ll n, vector<ll> graph[]) {
    ll visited[n];
    for(ll i = 0; i < n; i++) {
        visited[i] = 0;
    }

    ll cc = 0;
    for(ll i = 0; i < n; i++) {
        if(visited[i] == 0) {
            dfs(i, visited, graph);
            cc++;
        }
    }

    return cc;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll q;
  cin>>q;

  ll n,m;
  while(q--){
    cin>>n>>m;
    vector<ll> adj[n];

    ll a,b;
    fr(i,0,m){
      cin>>a>>b;
      adj[a].PB(b);
      adj[b].PB(a);
    }

    cout<<num_connections(n,adj)<<"\n";
  }

  return 0;
}
