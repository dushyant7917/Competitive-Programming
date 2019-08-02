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
#define N 10001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
bool visited[4*N];
ll ans=INF;
bool flag=false;

ll bfs(ll node){
  queue<pii> q;
  q.push(MP(node,0));

  ll v,d;
  while(q.size()){
    v=q.front().first;
    d=q.front().second;
    q.pop();

    if(v==m){
      return d;
    }

    visited[v]=true;
    if(v*2<=2*m && !visited[v*2]){
      q.push(MP(v*2,d+1));
    }
    if(v-1>0 && !visited[v-1]){
      q.push(MP(v-1,d+1));
    }
  }

  return INF;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;
  ans=bfs(n);
  if(ans==INF) cout<<-1;
  else cout<<ans;

  return 0;
}
