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

  ll m,n;
  cin>>n>>m;
  ll ans=1;
  fr(i,0,m){
    ans=((ans%mod)*((n-i)%mod))%mod;
  }
  cout<<ans;
  return 0;
}
