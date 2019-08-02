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
#define N 1000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll ETF(ll n){
  ll ans=n;

  for(ll i=2;i*i<=n;i++){
    if(n%i==0){
      while(n%i==0){
        n/=i;
      }
      ans-=ans/i;
    }
  }

  if(n>1) ans-=ans/n;

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;
    cout<<ETF(n)<<"\n";
  }

  return 0;
}
