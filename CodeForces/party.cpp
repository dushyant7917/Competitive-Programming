#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 2001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
vector<ll> graph[N];
bool is_root[N];
bool visited[N];
ll ans=0;

void dfs(ll v,ll d){
  visited[v]=true;
  ans=max(ans,d);

  fr(i,0,SZ(graph[v])){
    if(!visited[graph[v][i]]) dfs(graph[v][i],d+1);
  }
}

void cnt(){
  fr(i,1,n+1) if(is_root[i] && !visited[i]) dfs(i,1);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  MS(visited,false);

  cin>>n;

  ll x;
  fr(i,1,n+1){
    cin>>x;
    if(x!=-1){
      graph[x].PB(i);
      is_root[i]=false;
    }
    else is_root[i]=true;
  }

  cnt();
  cout<<ans;

  return 0;
}
