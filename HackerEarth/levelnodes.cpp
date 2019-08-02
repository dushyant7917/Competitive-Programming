#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define pb push_back
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN

void bfs(vector<ll> nodes[],ll level[],bool visited[]){
  queue<ll> q;
  q.push(1); // since 1 is the source/root node
  visited[1]=true;
  level[1]=1;

  ll cur_node;
  while(!q.empty()){
    cur_node=q.front();
    q.pop();
    //cout<<cur_node<<" ";
    fr(i,0,nodes[cur_node].size()){ // traversing all neighbour nodes in order
      if(visited[nodes[cur_node][i]]==false){ // if node is not visited before
        q.push(nodes[cur_node][i]);
        visited[nodes[cur_node][i]]=true;
        level[nodes[cur_node][i]]=level[cur_node]+1; // level of node = level of parent + 1
      }
    }
  }
}

ll level_nodes(ll x,ll level[],ll n){
  ll cnt=0;
  fr(i,1,n+1){
    if(level[i]==x) cnt++;
  }
  return cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;

  vector<ll> nodes[n+1];
  ll level[n+1];
  bool visited[n+1]={false};

  ll a,b;
  fr(i,0,n-1){
    cin>>a>>b;
    nodes[a].pb(b);
    nodes[b].pb(a);
  }

  //cout<<"\n";
  bfs(nodes,level,visited);
  //cout<<"\n";

  ll x;
  cin>>x;
  //cout<<x;
  cout<<level_nodes(x,level,n);

  return 0;
}
