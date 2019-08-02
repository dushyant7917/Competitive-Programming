#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define mod 1000000007

void max_prime_factor(ll n)
{
    ll max_prime=2;

    // Prll the number of 2s that divide n
    while (n%2 == 0)
    {
        //max_prime=max(2LL,max_prime);
        n = n/2;
    }

    // n must be odd at this poll.  So we can skip one element (Note i = i+2)
    for (ll i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, prll i and divide n
        while (n%i == 0)
        {
            max_prime=max(i,max_prime);
            n = n/i;
        }
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2)
        max_prime=max(n,max_prime);

    cout<<max_prime<<"\n";
}

void max_pf(ll n){
  ll max_prime=1;
  for(ll i=2;i*i<=n;i++){
    while(n%i==0){
      max_prime=i;
      n/=i;
    }
  }
  if(n>1){
    max_prime=n;
  }
  cout<<max_prime<<"\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;
    max_pf(n);
    //max_prime_factor(n);
  }

  return 0;
}
