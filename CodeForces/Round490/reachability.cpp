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
#define N 5001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m,s;
ll par[N];
bool visited[N];
vector<ll> adj[N];

void createSet(ll n){
  fr(i,1,n+1) par[i]=i;
}

bool reachable(ll u,ll v){
  if(u==v) return true;

  visited[u]=true;
  bool flag=false;

  fr(i,0,SZ(adj[u])){
    if(visited[adj[u][i]]) continue;
    if(reachable(adj[u][i],v)) flag=true;
  }

  return flag;
}

ll findSet(ll x){
  if(par[x]!=x) par[x]=findSet(par[x]);
  return par[x];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m>>s;

  ll u[m],v[m];
  fr(i,0,m){
    cin>>u[i]>>v[i];
    adj[u[i]].PB(v[i]);
  }

  createSet(n);

  ll xx,yy;
  fr(i,0,m){
    fr(j,1,n+1) visited[j]=false;
    xx=findSet(u[i]);
    yy=findSet(v[i]);
    if(yy!=s && xx!=yy && reachable(xx,yy)) par[yy]=xx;
  }

  ll ans=0;
  fr(i,1,n+1) if(par[i]==i) ans++;
  cout<<ans-1;

  return 0;
}
