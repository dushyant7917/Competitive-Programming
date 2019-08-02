#include<bits/stdc++.h>

using namespace std;

typedef unsigned long ll;
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
  ll m=4294967296;
  ll total;
  while(t--){
    cin>>n;
    total=m-86000;
    ll a[n];
    a[0]=43000;
    cout<<a[0];
    fr(i,1,n){
      a[i]=total/(n-i);
      total-=a[i];
      cout<<" "<<a[i];
    }
    cout<<"\n";
  }

  return 0;
}
