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

ll n,m;
vector<ll> graph[N];
vector<ll> cmp[2];
ll component[N];

void init(){
  fr(i,1,n+1) component[i]=-1;
}

bool flag=true;

void bfs(ll node){
  queue<ll> q;

  component[node]=0;
  cmp[0].PB(node);
  q.push(node);

  ll v,c;
  while(q.size()){
    v=q.front();
    c=component[v];
    q.pop();
    fr(i,0,SZ(graph[v])){
      if(component[graph[v][i]]==-1){
        component[graph[v][i]]=1-c;
        cmp[1-c].PB(graph[v][i]);
        q.push(graph[v][i]);
      }
      else if(component[graph[v][i]]==component[v]){
        flag=false;
        return;
      }
      else {}
    }
  }
}

void solve(){
  fr(i,1,n+1){
    if(component[i]==-1) bfs(i);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  init();

  ll u,v;
  fr(i,0,m){
    cin>>u>>v;
    graph[u].PB(v);
    graph[v].PB(u);
  }

  solve();

  if(flag){
    fr(i,0,2){
      cout<<SZ(cmp[i])<<"\n";
      fr(j,0,SZ(cmp[i])){
        cout<<cmp[i][j]<<" ";
      }
      cout<<"\n";
    }
  }
  else cout<<-1;

  return 0;
}
