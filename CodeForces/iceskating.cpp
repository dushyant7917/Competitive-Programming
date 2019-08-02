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
#define N 1001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
ll x[N],y[N];
bool visited[N];

void dfs(ll v){
  visited[v]=true;
  fr(u,0,n){
    if(!visited[u]){
      if(x[v]==x[u] || y[v]==y[u]) dfs(u);
    }
  }
}

ll cnt(){
  ll ans=0;
  fr(i,0,n) if(!visited[i]) ans++,dfs(i);
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  fr(i,0,n){
    cin>>x[i]>>y[i];
  }

  cout<<cnt()-1;

  return 0;
}
