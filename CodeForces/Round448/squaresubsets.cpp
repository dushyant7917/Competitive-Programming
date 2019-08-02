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

bool isqrt(ll x) {
    int sh = __builtin_ctzll(x);
    x >>= (sh&~1);

    if (x&6) return false;

    int i;
    const int ITERATIONS = 5; // log log x - 1
    ll z = (3-x)>>1, y=x*z;
    for (i=0; i<ITERATIONS; i++) {
        ll w = (3 - z*y) >> 1;
        y *= w;
        z *= w;
    }
    assert(x==0 || (y*z == 1 && x*z == y));

    if (y & (1ull<<62)) y = -y;
    y &= ~(1ull<<63);

    if (y >= 1ull<<32) return false;

    return true;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  ll a[n];
  fr(i,0,n) cin>>a[i];

  ll cnt=0,p;
  fr(i,0,n){
    p=1;
    fr(j,i,n){
      p*=a[j];
      cout<<p<<"\n";
      if(isqrt(p)) cnt=((cnt%mod)+(1%mod))%mod;
    }
  }

  cout<<cnt;

  return 0;
}
