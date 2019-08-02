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
#define N 1000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll max_prime_factor(ll n){
  ll ans=0;
  for(ll i=2;i*i<=n;i++){
    if(n%i==0){
      ans=max(ans,i);
      while(n%i==0) n/=i;
    }
  }

  return max(ans,n);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll x2;
  cin>>x2;
  ll mpf=max_prime_factor(x2);
  ll min_x1=x2-mpf+1,max_x1=x2;

  ll ans=INF;
  fr(x1,min_x1,max_x1+1){
    mpf=max_prime_factor(x1);
    if(mpf==x1) continue;
    ans=min(ans,x1-mpf+1);
  }

  cout<<ans;

  return 0;
}
