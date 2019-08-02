#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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
#define N 200001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
ll p[N],a[N];
vector<ll> pos,val;
vector<ll> adj[N];
bool visited[N];

void dfs(ll v){
  visited[v]=true;
  pos.PB(v);
  val.PB(p[v]);

  ll u;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(!visited[u]){
      dfs(u);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  fr(i,1,n+1) cin>>p[i];

  string s;
  cin>>s;
  fr(i,0,SZ(s)){
    if(s[i]=='1'){
      adj[i+1].PB(i+2);
      adj[i+2].PB(i+1);
    }
  }

  MS(visited,false);
  fr(i,1,n+1){
    if(!visited[i]){
      val.clear();
      pos.clear();
      dfs(i);
      sort(pos.begin(),pos.end());
      sort(val.begin(),val.end());
      fr(i,0,SZ(val)) a[pos[i]]=val[i];
    }
  }

  sort(p+1,p+1+n);
  bool flag=true;
  fr(i,1,n+1){
    if(a[i]!=p[i]){
      flag=false;
      break;
    }
  }
  if(flag) cout<<"YES";
  else cout<<"NO";

  return 0;
}
