#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 200002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
vector<ll> adj[N],ans[N];
bool visited[N];
bool flag;

void dfs(ll v){
  visited[v]=true;

  ll u;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(visited[u]) continue;

    dfs(u);
    if(SZ(ans[u])%3==0) ans[v].PB(u);
    else if(SZ(ans[u])%3==2) ans[u].PB(v);
    else flag=false;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,u,v;
  while(t--){
    cin>>n;

    fr(i,1,n+1){
      visited[i]=false;
      adj[i].clear();
      ans[i].clear();
    }

    fr(i,0,n-1){
      cin>>u>>v;
      adj[u].PB(v);
      adj[v].PB(u);
    }

    flag=true;
    dfs(1);

    fr(i,1,n+1) if(SZ(ans[i])%3!=0) flag=false;

    if(!flag) cout<<"NO\n";
    else{
      cout<<"YES\n";
      fr(i,1,n+1){
        if(!SZ(ans[i])) continue;

        for(ll j=0;j<SZ(ans[i]);j+=3) cout<<i<<" "<<ans[i][j]<<" "<<ans[i][j+1]<<" "<<ans[i][j+2]<<"\n";
      }
    }
  }

  return 0;
}
