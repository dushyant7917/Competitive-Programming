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

ll visited[10001]={0};
ll dp[10001]={0};

ll dfs(vector<ll> graph[],ll node){
  visited[node]=1;
  ll l1=0,l2=0,len;

  fr(i,0,graph[node].size()){
    if(!visited[graph[node][i]]){
      len=dfs(graph,graph[node][i]);
      if(len>l1){
        l2=l1;
        l1=len;
      }
      else if(len>l2){
        l2=len;
      }
      else{
        // pass
      }
    }
  }

  dp[node]=l1+l2;
  return l1+1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  vector<ll> graph[n+1];

  ll u,v;
  fr(i,0,n-1){
    cin>>u>>v;
    graph[u].PB(v);
    graph[v].PB(u);
  }

  dfs(graph,1);

  ll ans=0;
  fr(i,1,n+1){
    ans=max(ans,dp[i]);
  }
  cout<<ans<<"\n";

  return 0;
}
