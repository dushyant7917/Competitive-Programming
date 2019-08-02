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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;
    ll m[n],w[n];
    fr(i,0,n) cin>>m[i];
    fr(i,0,n) cin>>w[i];

    sort(m,m+n);
    sort(w,w+n);

    ll ans=0;
    fr(i,0,n) ans+=m[i]*w[i];

    cout<<ans<<"\n";
  }

  return 0;
}
