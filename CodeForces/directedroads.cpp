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
#define N 200005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
ll x[N],v[N],t[N];
ll tag,num=0,cycle;

void dfs(ll node){
  if(v[node]==0){
    v[node]=tag;
    t[node]=(++num);
    dfs(x[node]);
  }
  else if(v[node]==tag){
    cycle=num-t[node]+1;
    return;
  }
  else return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;

  fr(i,1,n+1) cin>>x[i];

  ll b2p[n+1]; // used of storing pow(2,i)
  b2p[0]=1;
  fr(i,1,n+1) b2p[i]=(b2p[i-1]*2)%mod;

  MS(v,0);
  ll non_cycle=n,ans=1;

  fr(i,1,n+1){
    if(v[i]!=0) continue;
    cycle=0;
    tag=i;
    dfs(i);
    non_cycle-=cycle;
    if(cycle!=0) ans=((ans%mod)*((b2p[cycle]-2)%mod))%mod;
  }

  ans=((ans%mod)*(b2p[non_cycle]%mod))%mod;
  cout<<ans;

  return 0;
}
