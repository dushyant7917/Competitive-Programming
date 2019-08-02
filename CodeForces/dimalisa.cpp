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

bool prime(ll n){
  if(n<=1) return false;
  if(n<=3) return true;
  if(n%2==0 || n%3==0) return false;

  ll i=5;
  while(i*i<=n){
    if(n%i==0 || n%(i+2)==0) return false;
    i+=6;
  }

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  if(prime(n)) cout<<1<<"\n"<<n;
  else if(prime(n-2)) cout<<2<<"\n"<<2<<" "<<n-2;
  else if(prime(n-3)) cout<<2<<"\n"<<3<<" "<<n-3;
  else{
    ll x=2;
    while(x<n-4 && (!prime(x) || (n-x)%2==1)) x++;
    cout<<3<<"\n";
    cout<<x<<" ";
    n=n-x;
    x=2;
    while(x<n && (!prime(x) || !prime(n-x))) x++;
    cout<<x<<" "<<n-x;
  }

  return 0;
}
