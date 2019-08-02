#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll num_prime_factors(ll n){
  set<ll> pf;

  if(n%2==0) pf.insert(2);

  while(n%2==0) n/=2;

  for(ll i=3;i*i<=n;i+=2){
    if(n%i==0){
      pf.insert(i);
      while(n%i==0) n/=i;
    }
  }

  if(n>2) pf.insert(n);

  return SZ(pf);
}

vector<ll> ln;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll num=30;
  while(SZ(ln)<1000){
    if(num_prime_factors(num)>=3) ln.PB(num);
    num++;
  }

  ll n;
  while(t--){
    cin>>n;
    cout<<ln[n-1]<<"\n";
  }

  return 0;
}
