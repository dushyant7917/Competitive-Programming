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
#define N 101
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
vector<pii> adj[N];
bool visited[N];

bool dfs(ll v,ll dst,ll color){
  if(v==dst) return true;

  visited[v]=true;

  ll u,c;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i].second;
    c=adj[v][i].first;
    if(!visited[u] && c==color){
      if(dfs(u,dst,c)) return true;
    }
  }

  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  ll a,b,c;
  fr(i,0,m){
    cin>>a>>b>>c;
    adj[a].PB(pii(c,b));
    adj[b].PB(pii(c,a));
  }

  ll q,cnt;
  cin>>q;
  fr(i,0,q){
    cin>>a>>b;
    cnt=0;
    fr(c,1,N){
      MS(visited,false);
      if(dfs(a,b,c)) cnt++;
    }
    cout<<cnt<<"\n";
  }

  return 0;
}
