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

ll num_divisors(ll n){
  ll cnt=0;
  for(ll i=1;i*i<=n+1;i++){
    if(n%i==0){
      cnt++;
      if(n/i!=i) cnt++;
    }
  }

  return cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll a,b;
  while(t--){
    cin>>a>>b;
    cout<<num_divisors(__gcd(a,b))<<"\n";
  }

  return 0;
}
