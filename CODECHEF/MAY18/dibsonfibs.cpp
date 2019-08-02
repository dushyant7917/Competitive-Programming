// reference -> https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/ //
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

ll F(ll n){
  ll n_1=1,n_2=1,res;

  if(n==0) return 0;
  else if(n<=2) return 1;
  else{
    fr(i,3,n+1){
      res=(n_1+n_2)%mod;
      n_2=n_1;
      n_1=res;
    }
    return res%mod;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,m,ans,x,y;
  while(t--){
    cin>>m>>n;

    x=F(n-2);
    y=F(n-1);

    ll a[m+1],b[m+1];
    fr(i,1,m+1) cin>>a[i];
    fr(i,1,m+1) cin>>b[i];

    if(n==1){
      x=0;
      y=1;
    }

    ans=0;
    fr(i,1,m+1){
      ans=(ans+(x*a[i]))%mod;
      ans=(ans+(y*b[i]))%mod;
    }
    ans=(ans*m)%mod;

    cout<<ans<<"\n";
  }

  return 0;
}
