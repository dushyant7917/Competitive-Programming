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
    ll x[n];
    fr(i,0,n) cin>>x[i];
    sort(x,x+n);
    if(n==1) cout<<0<<"\n";
    else{
      ll ma=0;
      ll j=0;
      fr(i,1,n){
        ma+=abs(x[i]-x[j]);
        j=i;
      }
      cout<<ma<<"\n";
    }
  }

  return 0;
}
