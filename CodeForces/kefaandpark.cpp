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

ll n,m;
ll cats[100001];
ll cnt=0;

bool visited[100001];

void dfs(vector<ll> graph[],ll node,ll max_consecutive,ll cur_consecutive) {
  if(visited[node]==true) return;

  visited[node]=true;

  if(node!=1 && graph[node].size()==1){
    if(cur_consecutive+cats[node]>m || max_consecutive>m) {}
    else cnt++;
  }
  else{
    if(cats[node]==1){
      cur_consecutive++;
    }
    else{
      max_consecutive=max(max_consecutive,cur_consecutive);
      cur_consecutive=0;
    }
  }

  for(ll i=0;i<graph[node].size();i++) {
    dfs(graph,graph[node][i],max_consecutive,cur_consecutive);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;
  vector<ll> graph[n+1];

  fr(i,1,n+1){
    cin>>cats[i];
  }

  ll x,y;
  fr(i,0,n-1){
    cin>>x>>y;
    graph[x].PB(y);
    graph[y].PB(x);
  }

  fr(i,0,n+1) visited[i]=false;
  dfs(graph,1,0,0);

  cout<<cnt;

  return 0;
}
