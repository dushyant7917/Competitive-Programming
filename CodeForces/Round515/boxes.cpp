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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m,k;
  cin>>n>>m>>k;
  ll a[n+1],ps[n+1]={0};
  fr(i,1,n+1) cin>>a[i];
  fr(i,1,n+1) ps[i]=ps[i-1]+a[i];

  ll ans=n,ind1=0,ind2=0,ind3=0,box=m,capacity=k;

  rf(i,n,1){
    if(ps[n]-ps[i-1]>m*k){
      ind1=i;
      break;
    }
  }

  rf(i,n,1){
    if(a[i]>k){
      ind2=i;
      break;
    }
  }

  rf(i,n,1){
    if(ps[n]-ps[i-1]>m*k || a[i]>k) break;

    else if(a[i]<=capacity) capacity-=a[i];

    else{
      box--;

      if(!box){
        ind3=i;
        break;
      }
      
      capacity=k;
      capacity-=a[i];
    }
  }

  ans-=MAX(ind1,ind2,ind3);

  cout<<ans;

  return 0;
}
