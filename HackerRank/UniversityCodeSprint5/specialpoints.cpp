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
#define N 300001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) (ll)(s.size())
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m,a,b;
vector<ll> adj[N];
bool visited[N];
vector<ll> s;

void init(){
  fr(i,1,n+1){
    visited[i]=false;
  }
}

void dfs(ll v){
  visited[v]=true;
  s.PB(SZ(adj[v]));

  ll u;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(visited[u]) continue;
    dfs(u);
  }
}

bool check(ll x){
  ll l=0,m,h=SZ(s)-1;
  bool f1=false,f2=false;

  while(l<=h){
    m=(l+h)/2;
    if(a*s[m]<x){
      f1=true;
      break;
    }
    else h=m-1;
  }

  l=0,h=SZ(s)-1;

  while(l<=h){
    m=(l+h)/2;
    if(b*s[m]>x){
      f2=true;
      break;
    }
    else l=m+1;
  }

  return (f1 && f2);
}

ll F(){
  ll cnt=0;

  fr(i,0,SZ(s)){
    if(check(s[i])) cnt++;
  }

  return cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m>>a>>b;

  ll u,v;
  fr(i,0,m){
    cin>>u>>v;
    adj[u].PB(v);
    adj[v].PB(u);
  }

  init();

  ll ans=0;

  fr(i,1,n+1){
    if(visited[i]) continue;
    dfs(i);
    sort(s.begin(),s.end());
    ans+=F();
    s.clear();
  }

  cout<<ans;

  return 0;
}
