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
#define N 1001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

dbl F(ll n,ll k){
  dbl ans;

  if(n<=2) return 1/(dbl)n;

  if(n>=3 && k){
    if(n%4==2) n=n/2+1;
    else n-=n/2;
    k--;
  }

  while(n && k){
    if(n<=2) return 1.0;
    else if(n==3){
      if(k==1) return 0.5;
      else return 1.0;
    }
    else n-=n/2;
    k--;
  }

  if(n>0 && !k) ans=1/(dbl)n;
  if(!n && k) ans=1.0;

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll n,k;
  while(t--){
    cin>>n>>k;
    cout<<fixed<<setprecision(6)<<F(n,k)<<"\n";
  }

  return 0;
}
