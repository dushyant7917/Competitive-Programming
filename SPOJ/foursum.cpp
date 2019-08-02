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

ll bs(ll arr[],ll n,ll x){
  ll cnt=0,l=0,r=n-1,m,ind;

  while(l<=r){
    m=(l+r)/2;
    if(arr[m]==x){
      cnt++;

      ind=m-1;
      while(ind>=0 && arr[ind]==x){
        cnt++;
        ind--;
      }

      ind=m+1;
      while(ind<n && arr[ind]==x){
        cnt++;
        ind++;
      }
      return cnt;
    }
    else if(arr[m]<x){
      l=m+1;
    }
    else{
      r=m-1;
    }
  }

  return cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  ll a[n],b[n],c[n],d[n];

  fr(i,0,n) cin>>a[i]>>b[i]>>c[i]>>d[i];

  ll x[n*n],y[n*n];
  fr(i,0,n){
    fr(j,0,n){
      x[i*n+j]=a[i]+b[j];
      y[i*n+j]=c[i]+d[j];
    }
  }

  sort(y,y+n*n);

  ll ans=0;
  fr(i,0,n*n) ans+=bs(y,n*n,-x[i]);

  cout<<ans<<"\n";

  return 0;
}
