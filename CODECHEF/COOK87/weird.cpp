#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
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

  ll y;
  while(t--){
    cin>>y;

    ll ans=0;

    fr(i,1,701){
      if(y>=i) ans+=floor(sqrt(y-i));
    }

    cout<<ans<<"\n";
  }

  return 0;
}
