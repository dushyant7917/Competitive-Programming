#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define sz(s) s.size()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  ll a[n];
  fr(i,0,n) cin>>a[i];

  if(n<=2) cout<<n;
  else{
    ll l[n],r[n],ans=1;

    l[0]=1;
    fr(i,1,n){
      l[i]=(a[i]>a[i-1])?l[i-1]+1:1;
      ans=max(ans,l[i]);
    }
    r[n-1]=1;
    for(ll i=n-2;i>=0;i--){
      r[i]=(a[i+1]>a[i])?r[i]=r[i+1]+1:1;
      ans=max(ans,r[i]);
    }
    fr(i,1,n-1){
      if(a[i+1]-a[i-1]>1) ans=max(ans,l[i-1]+r[i+1]+1);
      else ans=MAX(ans,l[i-1]+1,r[i+1]+1);
    }
    ans=MAX(ans,l[n-2]+1,r[1]+1);
    cout<<ans;
  }

  return 0;
}
