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
    ll a[n],sign[n],b[n];
    fr(i,0,n){
      cin>>a[i];
      if(a[i]>0) sign[i]=1;
      else sign[i]=0;
    }

    b[n-1]=1;
    for(ll i=n-2;i>=0;i--){
      if(sign[i]!=sign[i+1]) b[i]=b[i+1]+1;
      else b[i]=1;
    }

    fr(i,0,n) cout<<b[i]<<" ";
    cout<<"\n";
  }

  return 0;
}
