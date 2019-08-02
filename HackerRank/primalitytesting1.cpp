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

bool primes[5000001];

void prime_nums(ll n){
  memset(primes, true, sizeof(primes)); // primes[0 to n] = true

  ll i,j;
  for(i=2;i*i<=n;i++){
    // i is still unmarked
    if(primes[i]){
      // Mark numbers which are mutiples of i excluding i itself
      for(j=i*2;j<=n;j=j+i){
        primes[j]=false;
      }
    }
  }

  primes[0]=primes[1]=false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  prime_nums(5000001);

  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;
    if(primes[n]) cout<<"yes\n";
    else cout<<"no\n";
  }

  return 0;
}
