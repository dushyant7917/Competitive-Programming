#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define pb push_back
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN

ll dfs(vector<ll> nodes[],bool visited[],ll source,ll total_nodes){
  ll cnt=0;
  stack<ll> s;
  s.push(source);
  visited[source]=true;
  ll cur_node;
  while(!s.empty()){
    cur_node=s.top();
    s.pop();
    cnt++;
    fr(i,0,nodes[cur_node].size()){
      if(!visited[nodes[cur_node][i]]){
        visited[nodes[cur_node][i]]=true;
        s.push(nodes[cur_node][i]);
      }
    }
  }
  return total_nodes-cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m;
  cin>>n>>m;
  vector<ll> nodes[n+1];
  bool visited[n+1]={false};

  ll a,b;
  fr(i,0,m){
    cin>>a>>b;
    nodes[a].pb(b);
    nodes[b].pb(a);
  }

  ll x;
  cin>>x;

  cout<<dfs(nodes,visited,x,n);

  return 0;
}
