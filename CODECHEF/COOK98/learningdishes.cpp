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
#define N 1000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

ll n,q,x,a,b,prv,ans,l,timer;
vector<ll> adj[N];
ll taste[N],mx[N],cnt[N],up[N][21];
bool visited[N];

void init(){
  l=(ll)(ceil(log2(n)));

  fr(i,0,n+1){
    adj[i].clear();
    visited[i]=false;
    mx[i]=0;
    cnt[i]=1;

    fr(j,0,l+1) up[i][j]=0;
  }
}

void dfs(ll v,ll p){
  visited[v]=true;
  up[v][0]=p;
  mx[v]=max(taste[v],mx[p]);
  cnt[v]=cnt[p];
  if(taste[v]>mx[p]) cnt[v]++;

  fr(i,1,l+1) up[v][i]=up[up[v][i-1]][i-1];

  ll u;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(visited[u]) continue;
    dfs(u,v);
  }
}

ll query(ll v,ll w){
  if(mx[1]>w) return cnt[v];
  if(mx[v]<=w) return 0;

  ll x=v;

  rf(i,l,0) if(mx[up[x][i]]>w) x=up[x][i];

  return cnt[v]-cnt[up[x][0]];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  while(t--){
    cin>>n;

    init();

    fr(i,1,n+1) cin>>taste[i];

    fr(i,2,n+1){
      cin>>x;
      adj[x].PB(i);
      adj[i].PB(x);
    }

    dfs(1,1);

    cin>>q;

    prv=0;

    fr(i,0,q){
      cin>>a>>b;
      ans=query(a^prv,b^prv);
      cout<<ans<<"\n";
      prv=ans;
    }
  }

  return 0;
}
