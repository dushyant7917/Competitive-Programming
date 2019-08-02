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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,k;
  while(t--){
    cin>>n>>k;
    k=min(n/2,k);

    ll a[n+1];
    vector<ll> m,t;
    m.PB(INF);
    t.PB(-INF);

    fr(i,1,n+1){
      cin>>a[i];
      if(i%2!=0) m.PB(a[i]);
      else t.PB(a[i]);
    }

    ll ms,ts;
    ll mps[n+1]={0},tps[n+1]={0};
    ms=ts=0;

    sort(t.begin(),t.end());
    sort(m.begin(),m.end(),greater<ll>());

    fr(i,1,SZ(m)){
      ms+=m[i];
      mps[i]=mps[i-1]+m[i];
    }

    fr(i,1,SZ(t)){
      ts+=t[i];
      tps[i]=tps[i-1]+t[i];
    }

    if(ts>ms) cout<<"YES\n";
    else{
      if(ms-mps[k]+tps[k]<ts-tps[k]+mps[k]) cout<<"YES\n";
      else cout<<"NO\n";
    }
  }

  return 0;
}
