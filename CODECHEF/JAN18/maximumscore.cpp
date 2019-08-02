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

ll bs(ll a[],ll l,ll r,ll x){
  ll res=-1,m;

  while(l<=r){
    m=(l+r)/2;
    if(a[m]<x){
      res=m;
      l=m+1;
    }
    else r=m-1;
  }

  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,v,ind,ans;
  bool flag;
  while(t--){
    cin>>n;

    ll a[n][n];
    fr(i,0,n){
      fr(j,0,n) cin>>a[i][j];
    }

    fr(i,0,n){
      sort(a[i],a[i]+n);
    }
    if(n==1) cout<<a[0][n-1]<<"\n";
    else{
      flag=true;
      v=a[n-1][n-1];
      ans=v;

      for(ll i=n-2;i>=0;i--){
        ind=bs(a[i],0,n-1,v);
        if(ind==-1){
          flag=false;
          break;
        }
        v=a[i][ind];
        ans+=v;
      }

      if(flag) cout<<ans<<"\n";
      else cout<<-1<<"\n";
    }
  }

  return 0;
}
