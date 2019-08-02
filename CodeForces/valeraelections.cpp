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
ll white[N];
bool visited[N];
vector<ll> adj[N];

ll dfs(ll v){
  visited[v]=true;

  ll u;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(!visited[u]){
      white[v]+=dfs(u);
    }
  }

  return white[v];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  MS(white,0);

  cin>>n;
  ll x,y,t;
  fr(i,0,n-1){
    cin>>x>>y>>t;
    if(t==2){
      white[x]=white[y]=1;
    }
    adj[x].PB(y);
    adj[y].PB(x);
  }

  MS(visited,false);
  white[1]=dfs(1);

  vector<ll> v;
  fr(i,1,n+1){
    if(white[i]==1) v.PB(i);
  }

  cout<<v.size()<<"\n";
  fr(i,0,SZ(v)) cout<<v[i]<<" ";

  return 0;
}
