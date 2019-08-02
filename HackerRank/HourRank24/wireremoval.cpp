#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9

vector<ll> graph[100001];
ll visited[100001]={0};
ll nns[100001];
ll n,num=0,den=0;

void dfs(ll node,ll lev) {
  visited[node]=1;
  nns[node]=1;

  fr(i,0,graph[node].size()){
    if(!visited[graph[node][i]]){
      dfs(graph[node][i],lev+1);
      nns[node]+=nns[graph[node][i]];
    }
  }

  if(node!=1){
    num+=(lev*1LL*(n-nns[node]));
    den+=lev;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;

  ll u,v;
  fr(i,0,n-1){
    cin>>u>>v;
    graph[u].PB(v);
    graph[v].PB(u);
  }

  dfs(1,0);

  dbl ans=(dbl)num/(dbl)den;

  cout<<fixed<<setprecision(10)<<ans<<"\n";

  return 0;
}
