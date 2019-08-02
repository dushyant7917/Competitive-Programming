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

  ll n,k;
  while(t--){
    cin>>n>>k;
    ll a[n];
    ll cnt=0;
    fr(i,0,n){
      cin>>a[i];
      if((a[i]+k)%7==0) cnt++;
    }
    cout<<cnt<<"\n";
  }

  return 0;
}
