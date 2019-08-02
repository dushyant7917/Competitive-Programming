#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define mod 1000000007

vector<ll> pf;

ll sum_digits(ll n){
  ll sum=0;
  while(n){
    sum+=n%10;
    n/=10;
  }
  return sum;
}

ll sum_prime_factors(ll n)
{
    // Print all the number of 2s that divide n
    while (n%2 == 0)
    {
        //max_prime=max(2LL,max_prime);
        pf.push_back(2);
        n = n/2;
    }

    // n must be odd at this poll.  So we can skip one element (Note i = i+2)
    for (ll i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, prll i and divide n
        while (n%i == 0)
        {
            pf.push_back(i);
            n = n/i;
        }
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2)
        pf.push_back(n);

    ll sum=0;
    fr(0,pf.size()){
      sum+=sum_digits(pf[i]);
    }

    return sum;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  if(sum_prime_factors(t)==sum_digits(t)){
    cout<<1;
  }
  else{
    cout<<0;
  }


  return 0;
}
