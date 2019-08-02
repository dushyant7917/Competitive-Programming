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

ll visited[100000]={0};

ll dfs(vector<ll> graph[], ll source_node){
  stack<ll> s;
  s.push(source_node);
  visited[source_node] = 1;

  ll num_nodes_connected=0;
  ll cur_node;
  while(!s.empty()){
    num_nodes_connected++;
    cur_node = s.top();
    s.pop();
    for(ll i = 0; i<graph[cur_node].size(); i++){
      if(visited[graph[cur_node][i]] == 0){
        visited[graph[cur_node][i]] = 1;
        s.push(graph[cur_node][i]);
      }
    }
  }

  return num_nodes_connected;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,p;
  cin>>n>>p;

  vector<ll> nodes[n];
  ll a,b;
  fr(i,0,p){
    cin>>a>>b;
    nodes[a].PB(b);
    nodes[b].PB(a);
  }

  ll nnc; // number of nodes connected
  ll nwsc=0; // total number of ways of selecting from same component
  ll tnw=(n*(n-1))/2; // total number of ways of selecting a pair or two nodes
  fr(i,0,n){
    if(visited[i]==0){
      nnc=dfs(nodes,i);
      nwsc+=((nnc*(nnc-1))/2);
    }
  }

  cout<<tnw-nwsc;

  return 0;
}
