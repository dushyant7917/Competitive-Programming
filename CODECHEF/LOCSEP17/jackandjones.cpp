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

ll digit_sum(ll n){
  ll ds=0;
  while(n>0){
    ds+=n%10;
    n/=10;
  }
  return ds;
}

ll pfs[1000001]={0};
ll dsn[1000001]={0};

void sd(ll n){
  fr(i,0,n){
    dsn[i]=digit_sum(i);
  }
}

void pfs_sieve(ll n){
  ll i,j;
  for(i=2;i*i<=n;i++){
    // i is prime
    if(pfs[i]==0){
      // calculating pfs for all mutiples of i excluding i itself
      for(j=i*2;j<=n;j=j+i){
        pfs[j]+=dsn[i];
      }
      pfs[i]=dsn[i];
    }
  }

}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  sd(1001);
  pfs_sieve(1000001);

  ll t;
  cin>>t;

  ll l,r;
  while(t--){
    cin>>l>>r;
    ll sum=0;
    fr(i,l,r+1){
      sum=(sum%mod)+(pfs[i]%mod);
    }
    cout<<sum%mod;
    cout<<"\n";
  }

  return 0;
}
