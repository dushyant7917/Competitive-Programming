#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007

bool primes[n+1];

void sieve(ll n){
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

  sieve(100001);

  ll t;
  cin>>t;

  ll n,k,cnt;
  while(t--){
    cin>>n>>k;
    cnt=0;
    fr(2,n+1){
      
    }
  }

  return 0;
}
