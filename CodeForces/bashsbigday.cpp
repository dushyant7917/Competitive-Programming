#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  ll a[n];
  fr(i,0,n) cin>>a[i];

  ll num,p,x,f[N]={0};
  fr(i,0,n){
    num=a[i];
    x=sqrt(a[i]);
    p=2;
    while(p<=x){
      if(num%p==0){
        f[p]++;
        while(num%p==0) num/=p;
      }
      p++;
    }
    if(num>1) f[num]++;
  }


  ll ans=1;
  fr(i,2,N) ans=max(ans,f[i]);
  cout<<ans;

  return 0;
}
