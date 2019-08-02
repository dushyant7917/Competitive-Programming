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

ll n,t,m;
vector<ll> nodes[101];
bool visited[101];
ll new_childs;

ll dfs(ll node){
  ll childs=0;
  visited[node]=true;

  fr(i,0,nodes[node].size()){
    if(visited[nodes[node][i]]==false){
      new_childs=1+dfs(nodes[node][i]);
      childs+=new_childs;
    }
  }

  cout<<node<<" childs:"<<childs<<"\n";

  return childs;
}

void initialize(){
  fr(i,0,n+1) visited[i]=false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  ll a,b;
  while(t--){
    cin>>n>>t>>m;
    fr(i,0,m){
      cin>>a>>b;
      nodes[a].PB(b);
      nodes[b].PB(a);
    }
    initialize();
    dfs(1);
    fr(i,0,101) nodes[i].clear();
  }

  return 0;
}
