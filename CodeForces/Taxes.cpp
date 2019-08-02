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
#define INF 2e10
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

ll F(ll n){
  if(prime(n)) return 1;
  else if(n%2==0 || prime(n-2)) return 2;
  else return 3;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  cout<<F(n);

  return 0;
}
