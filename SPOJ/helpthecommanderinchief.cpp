#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
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

ll n,m,src,dst,cnt;
ll dp[N];
vector<ll> adj[N];

void init(ll n){
  fr(i,1,n+1){
    dp[i]=-1;
    adj[i].clear();
  }
}

ll dfs(ll v){
  if(v==dst) return 1;

  if(dp[v]!=-1) return dp[v];

  ll u,paths=0;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    paths=(paths+dfs(u))%mod;
  }

  dp[v]=paths;
  cout<<"v:"<<v<<" dp[v]:"<<dp[v]<<"\n";
  return dp[v];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll a,b;
  while(t--){
    cin>>n>>m>>src>>dst;

    init(n);

    fr(i,0,m){
      cin>>a>>b;
      adj[a].PB(b);
    }

    cout<<dfs(src)<<"\n";
  }

  return 0;
}
