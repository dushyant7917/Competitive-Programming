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

  ll a[n+1];

  if(n==1) cout<<1<<"\n";
  else if(n==2) cout<<1<<" "<<2<<"\n";
  else{
    ll ind=1,m=n/2,x=2;

    while(ind<m) a[ind++]=x++;

    ind=n-2;
    x=n-1;

    while(ind>m) a[ind--]=x--;

    a[n]=x;
    a[m]=1;
    a[n-1]=n;

    fr(i,1,n+1) cout<<a[i]<<" "; cout<<"\n";
  }

  a[n]=n-1;
  a[1]=n;

  fr(i,2,n) a[i]=i-1;

  fr(i,1,n+1) cout<<a[i]<<" ";

  return 0;
}
