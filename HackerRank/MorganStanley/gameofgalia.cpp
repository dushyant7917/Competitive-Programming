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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;
    ll a[n];
    fr(i,0,n) cin>>a[i];

    if(n==1){
      cout<<a[0]<<"\n";
    }
    else{
      sort(a,a+n);

      ll sum=0;
      fr(i,0,n){
        if(i==0 || i==n-1) sum+=a[i]*3;
        else sum+=a[i]*2;
      }

      ll d=__gcd(sum,6LL);
      if(6/d==1) cout<<(sum/d)<<'\n';
      else cout<<(sum/d)<<'/'<<(6/d)<<"\n";
    }

  }

  return 0;
}
