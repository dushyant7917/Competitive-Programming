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

ll fn(ll n,ll a[],ll d){
  ll b[n];

  ll k=0;
  fr(i,d,n) b[k++]=a[i];
  fr(i,0,d) b[k++]=a[i];

  ll hd=0;
  fr(i,0,n) if(a[i]!=b[i]) hd++;

  return hd;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,mhd,r,k;
  while(t--){
    cin>>n;
    ll a[n],b[n];
    fr(i,0,n) cin>>a[i];

    mhd=0,r=0;
    fr(i,0,n){
      if(fn(n,a,i)>mhd){
        r=i;
        mhd=fn(n,a,i);
        if(mhd==n) break;
      }
    }

    k=0;
    fr(i,r,n) b[k++]=a[i];
    fr(i,0,r) b[k++]=a[i];

    cout<<mhd<<"\n";
    fr(i,0,n) cout<<b[i]<<" ";
    cout<<"\n";
  }

  return 0;
}
