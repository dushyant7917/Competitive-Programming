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

  ll n,r;
  ll rm,lm;
  while(t--){
    cin>>n>>r;

    rm=INF;
    lm=-1;

    ll a[n];
    fr(i,0,n) cin>>a[i];

    bool flag=true;
    fr(i,0,n-1){
      if(a[i]>rm || a[i]<lm){
        cout<<"NO\n";
        flag=false;
        break;
      }
      if(a[i]>r) rm=a[i];
      if(a[i]<r) lm=a[i];
    }

    if(flag) cout<<"YES\n";
  }

  return 0;
}
