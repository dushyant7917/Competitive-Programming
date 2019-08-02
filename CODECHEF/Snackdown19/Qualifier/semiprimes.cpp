#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

bool semiPrime(ll n){
  set<ll> s;
  ll cnt=0;

  while(n%2==0){
    cnt++;
    s.insert(2);
    n/=2;
  }

  for(ll i=3;i*i<=n;i+=2){
    while(n%i==0){
      cnt++;
      s.insert(i);
      n/=i;
    }
  }

  if(n>2){
    cnt++;
    s.insert(n);
  }

  return (cnt==2 && SZ(s)==2)?true:false;
}

bool check(ll n){
  fr(i,1,n){
    if(semiPrime(i) && semiPrime(n-i)){
      return true;
    }
  }

  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;
    if(check(n)) cout<<"YES\n";
    else cout<<"NO\n";
  }

  return 0;
}
