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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
bool visited[N];
ll tax[N];
vector<ll> cmp;
vector<ll> adj[N];
ll min_tax;

void dfs(ll v){
  visited[v]=true;
  if(tax[v]>=0 && min_tax==-1) min_tax=tax[v];
  if(tax[v]>=0 && min_tax>=0 && tax[v]<min_tax) min_tax=tax[v];

  ll u;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(visited[u]) continue;
    dfs(u);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  ll u,v;

  fr(i,0,m){
    cin>>u>>v;
    adj[u].PB(v);
    adj[v].PB(u);
  }

  fr(i,1,n+1) cin>>tax[i];

  fr(i,0,n+1) visited[i]=false;

  ll cnt=0;

  fr(i,1,n+1){
    if(visited[i]) continue;

    cnt++;
    min_tax=-1;
    dfs(i);
    if(min_tax!=-1) cmp.PB(min_tax);
  }

  if(cnt==1) cout<<0;
  else if(SZ(cmp)==cnt){
    ll ans=0;
    sort(cmp.begin(),cmp.end());
    fr(i,1,SZ(cmp)) ans+=(cmp[0]+cmp[i]);
    cout<<ans;
  }
  else cout<<-1;

  return 0;
}
