#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,k;
  while(t--){
    cin>>n>>k;
    ll a[n];
    fr(i,0,n) cin>>a[i];

    sort(a,a+n);

    ll ans=INF;
    fr(i,0,n-k+1){
      ans=min(ans,a[i+k-1]-a[i]);
    }
    cout<<ans<<"\n";
  }

  return 0;
}
