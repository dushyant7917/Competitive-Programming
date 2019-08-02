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
#define N 200005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,q;
vector<ll> adj[N];
bool visited[N];
ll num[N],pos[N];
map<ll,ll> mp;

void init(){
  fr(i,1,n+1){
    visited[i]=false;
    num[i]=0;
    pos[i]=0;
  }
}

ll len=1;

ll dfs(ll v){
  visited[v]=true;
  pos[v]=len;
  mp[len]=v;

  ll u;

  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(visited[u]) continue;
    len++;
    dfs(u);
  }


  num[v]=len-pos[v]+1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>q;

  ll x;
  fr(i,2,n+1){
    cin>>x;
    adj[x].PB(i);
  }

  fr(i,1,n+1) sort(adj[i].begin(),adj[i].end());

  init();
  dfs(1);

  ll u,k;
  fr(i,0,q){
    cin>>u>>k;
    if(k>num[u]) cout<<-1<<"\n";
    else cout<<mp[pos[u]+k-1]<<"\n";
  }

  return 0;
}
