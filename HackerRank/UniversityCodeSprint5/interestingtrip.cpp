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
#define N 200001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m,src,dst;
vector<ll> adj[N];
char name[N];
bool visited[N];
set<string> ans;

void init(){
  fr(i,1,n+1){
    visited[i]=false;
  }
}

void dfs(ll v,string s){
  visited[v]=true;
  s+=name[v];

  if(v==dst){
    ans.insert(s);
    return;
  }

  ll u;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(visited[u] && u!=dst) continue;
    dfs(u,s);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  string r;
  cin>>r;

  fr(i,0,SZ(r)) name[i+1]=r[i];

  ll u,v;
  fr(i,0,m){
    cin>>u>>v;
    adj[u].PB(v);
  }

  cin>>src>>dst;

  init();
  string path="";

  dfs(src,path);

  //for(set<string>::iterator itr=ans.begin();itr!=ans.end();itr++) cout<<(*itr)<<"\n"; cout<<"\n";

  if(SZ(ans)) cout<<(*(ans.begin()));
  else cout<<"No way";

  return 0;
}
