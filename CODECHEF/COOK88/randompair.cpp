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

  ll n;
  while(t--){
    cin>>n;
    ll a[n];
    ll mv=-INF;
    fr(i,0,n) cin>>a[i];

    fr(i,0,n-1){
      fr(j,i+1,n){
        mv=max(mv,a[i]+a[j]);
      }
    }
    ll cnt=0;
    fr(i,0,n-1){
      fr(j,i+1,n) if(a[i]+a[j]==mv) cnt++;
    }
    n--;
    cout<<fixed<<setprecision(8)<<(dbl)cnt/(dbl)((n*(n+1))/2)<<"\n";
  }

  return 0;
}
