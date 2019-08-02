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
#define N 200002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,q;
ll a[N],k[N],ps[N];

ll bs(ll ind,ll &left,ll x){
  ll pos=ind-1,l=ind,h=n,m;

  while(l<=h){
    m=(l+h)/2;
    if(ps[m]-ps[ind-1]-left<=x){
      pos=m;
      l=m+1;
    }
    else h=m-1;
  }

  if(ps[pos]-ps[ind-1]-left<x && pos<n) left=a[pos+1]-(ps[pos+1]-ps[ind-1]-left-x);
  else left=0;
  pos++;
  if(pos>n) pos=1;

  return pos;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>q;

  ps[0]=0;

  fr(i,1,n+1){
    cin>>a[i];
    ps[i]=a[i]+ps[i-1];
  }

  fr(i,1,q+1) cin>>k[i];

  ll ind=1,left=0;

  fr(i,1,q+1){
    ind=bs(ind,left,k[i]);
    cout<<(n-ind+1)<<"\n";
  }

  return 0;
}
