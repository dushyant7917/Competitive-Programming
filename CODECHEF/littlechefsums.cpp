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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;
    ll a[n],p[n],s[n];
    fr(i,0,n) cin>>a[i];
    p[0]=a[0];
    fr(i,1,n){
      p[i]=p[i-1]+a[i];
    }
    s[n-1]=a[n-1];
    for(ll i=n-2;i>=0;i--){
      s[i]=s[i+1]+a[i];
    }
    ll mi=0,m=p[0]+s[0];
    fr(i,1,n){
      if(p[i]+s[i]<m){
        m=p[i]+s[i];
        mi=i;
      }
    }
    cout<<mi+1<<"\n";
  }

  return 0;
}
