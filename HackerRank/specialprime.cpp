#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define mod 1000000007

#define K 10000000
bool primes[K];

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

}

bool prime_num(ll n){
    // corner cases
    if(n<=1)return false;
    if(n<=3)return true;

    // Below code is checked so that we can skip middle 5 numbers in the later while loop
    if(n%2==0 || n%3==0)return false;

    ll i=5;
    while(i*i<=n){
        if(n%i==0 || n%(i+2)==0)return false;
        i+=6;
    }

    return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  prime_nums(K);
  primes[0]=primes[1]=false;

  ll n;
  while(t--){
    cin>>n;
    ll sum=0;
    for(ll i=2;i*i<=n;i++){
      if(n%i==0){
        sum+=i;
        if(n/i!=i)sum+=n/i;
      }
    }
    if(primes[sum+1]){
      cout<<"YES\n";
    }
    else{
      cout<<"NO\n";
    }
  }

  return 0;
}
