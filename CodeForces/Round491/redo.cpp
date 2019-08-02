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
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  ll a[n],b[n];
  fr(i,0,n) cin>>a[i];

  ll cnt=0;
  fr(i,0,n) if(a[i]<5) cnt++;

  if(cnt==0){
    cout<<0;
    return 0;
  }

  sort(a,a+n);

  ll ans,ind;
  fr(i,0,n+1){
    fr(j,0,n) b[j]=a[j];

    if(i){
      fr(j,0,n){
        if(a[j]<5){
          ind=j;
          break;
        }
      }

      fr(j,ind,min(ind+i,n)) b[j]=5;
    }

    dbl sum=0.0;
    fr(j,0,n) sum+=(dbl)b[j];
    dbl avg=sum/(dbl)n;
    if(avg>=4.5){
      ans=i;
      break;
    }
  }

  cout<<ans;

  return 0;
}
