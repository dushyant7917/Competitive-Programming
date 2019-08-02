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
#define N 1000000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<ll> v;
  v.PB(0);

  ll dist=1;
  while(v[SZ(v)-1]<N){
    v.PB(v[SZ(v)-1]+dist);
    dist++;
  }

  ll t;
  cin>>t;

  ll n,ans;
  while(t--){
    cin>>n;
    ans=INF;
    fr(i,0,SZ(v)){
      ans=min(ans,abs(v[i]-n)+i);
    }
    cout<<ans<<"\n";
  }

  return 0;
}
