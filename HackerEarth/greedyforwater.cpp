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

  ll t;
  cin>>t;

  ll n,x;
  while(t--){
    cin>>n>>x;
    ll a[n];
    fr(i,0,n) cin>>a[i];

    sort(a,a+n);

    ll k=0,cc=x,cnt=0;
    while(a[k]<=cc && k<n){
      cnt++;
      cc=cc-a[k];
      k++;
    }
    cout<<cnt<<"\n";
  }

  return 0;
}
