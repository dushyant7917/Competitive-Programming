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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
vector<ll> adj[N];
bool visited[N];
ll color[2];

void dfs(ll v,bool c){
  color[c]++;
  visited[v]=true;

  ll u;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(!visited[u]){
      dfs(u,1-c);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;

  ll x,y;
  fr(i,0,n-1){
    cin>>x>>y;
    adj[x].PB(y);
    adj[y].PB(x);
  }

  MS(color,0);
  MS(visited,false);
  dfs(1,0);
  cout<<(color[0]*color[1])-(n-1);

  return 0;
}
