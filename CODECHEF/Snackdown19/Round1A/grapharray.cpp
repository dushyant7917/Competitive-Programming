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
#define N 101
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
ll a[N];
ll cmp;
set<ll> unVisited;

void init(){
  unVisited.clear();
}

void dfs(ll v){
  unVisited.erase(v);

  ll u=0;
  set<ll>::iterator itr;

  while(1){
    itr=unVisited.lower_bound(u);
    if(itr==unVisited.end()) break;
    u=(*itr);
    if(__gcd(a[v],a[u])!=1){
      u++;
      continue;
    }
    dfs(u);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  while(t--){
    cin>>n;
    fr(i,1,n+1) cin>>a[i];

    init();

    fr(i,1,n+1) unVisited.insert(i);

    cmp=0;
    fr(i,1,n+1){
      if(unVisited.count(i)){
        cmp++;
        dfs(i);
      }
    }

    if(cmp==1) cout<<0<<"\n";

    else{
      bool all47=true,is47=false;

      fr(i,1,n+1){
        if(a[i]!=47) all47=false;
        if(a[i]==47) is47=true;
      }

      if(!is47) a[1]=47;
      else if(all47) a[1]=2;
      else {}

      cout<<1<<"\n";
    }

    fr(i,1,n+1) cout<<a[i]<<" "; cout<<"\n";
  }

  return 0;
}
