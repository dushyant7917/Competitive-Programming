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

bool visited[101];
ll n,m;
ll a,b;

ll ans=0,num_nodes_new;

ll dfs(vector<ll> nodes[],ll start_node){
  ll num_nodes=0;
  visited[start_node]=true;

  fr(i,0,nodes[start_node].size()){
    if(!visited[nodes[start_node][i]]){
      num_nodes_new=dfs(nodes,nodes[start_node][i]);
      if(num_nodes_new%2==0) ans++;
      else num_nodes+=num_nodes_new;
    }
  }

  return num_nodes+1;
}

void initialize(){
  fr(i,1,n+1) visited[i]=false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n>>m;
  vector<ll> nodes[n+1];
  fr(i,0,m){
    cin>>a>>b;
    nodes[a].PB(b);
    nodes[b].PB(a);
  }

  initialize();
  dfs(nodes,1);
  cout<<ans;

  return 0;
}
