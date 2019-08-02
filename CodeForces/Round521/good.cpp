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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  ll a[n];
  fr(i,0,n) cin>>a[i];

  ll sum=0;
  multiset<ll> ms;
  fr(i,0,n){
    ms.insert(a[i]);
    sum+=a[i];
  }

  ll ans=0,rem,val;
  vector<ll> ind;

  fr(i,0,n){
    rem=sum-a[i];
    ms.erase(ms.find(a[i]));
    val=*(--ms.end());
    if(val==rem-val){
      ans++;
      ind.PB(i+1);
    }
    ms.insert(a[i]);
  }

  cout<<ans<<"\n";
  if(ans){
    fr(i,0,SZ(ind)) cout<<ind[i]<<" ";
    cout<<"\n";
  }

  return 0;
}
