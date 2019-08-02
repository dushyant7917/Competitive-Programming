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
    ll a[n];
    map<ll,ll> mp;
    fr(i,0,n){
      cin>>a[i];
      mp[a[i]]++;
    }
    sort(a,a+n);
    fr(i,0,n){
      if(mp[a[i]]==1){
        cout<<a[i]<<"\n";
        break;
      }
    }
  }

  return 0;
}
