#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 1000000
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll b[N];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  ll a[n];
  fr(i,0,n) cin>>a[i];


  MS(b,0);
  fr(i,0,n) b[a[i]]=1;

  ll tm1=0,tm2=0,ans;

  ll l=1,r=N;

  fr(i,2,N/2+1){
    if(b[i]){
      tm1+=i-l;
      l=i;
    }
  }

  tm2=0;
  rf(i,N-1,N/2){
    if(b[i]){
      tm2+=abs(i-r);
      r=i;
    }
  }
  
  ans=max(tm1,tm2);

  cout<<ans;

  return 0;
}
