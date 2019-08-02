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

bool sign(ll a[],ll i){
  if(a[i]>0 && a[i-1]<0) return true;
  else if(a[i]<0 && a[i-1]>0) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,ind,reach;
  while(t--){
    cin>>n;
    ll a[n],ans[n];
    fr(i,0,n) cin>>a[i];

    reach=-1;

    fr(i,0,n){
      if(reach<i){
        ind=i;
        while(ind+1<=n-1 && sign(a,ind+1)) ind++;
        ans[i]=ind-i+1;
        reach=ind;
        //cout<<i<<"->"<<ind<<"\n";
      }
      else{
        if(ans[i-1]>1) ans[i]=ans[i-1]-1;
        else ans[i]=1;
      }
    }

    fr(i,0,n) cout<<ans[i]<<" "; cout<<"\n";
  }

  return 0;
}
