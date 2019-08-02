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

ll f[100001];

void factorial(ll n){
  f[0]=f[1]=1;
  fr(i,2,n){
    f[i]=((f[i-1]%mod)*(i%mod))%mod;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  factorial(100001);

  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;
    cout<<f[n]<<"\n";
  }

  return 0;
}
