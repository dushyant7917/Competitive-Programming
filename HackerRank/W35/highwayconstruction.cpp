#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000009
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,k,ans;
  while(t--){
    cin>>n>>k;

    if(k==1) ans=(n*(n+1))/2;
    else if(k==2) ans=(n*(n+1)*(2*n+1))/6;
    else if(k==3) ans=((n*n)*(n+1)*(n+1))/4;
    else if(k==4) ans=(n*(n+1)*(2*n+1)*(3*n*n+3*n-1))/30;
    else if(k==5) ans=((n*n)*(n+1)*(n+1)*(2*n*n+2*n-1))/12;
    else if(k==6) ans=(n*(n+1)*(2*n+1)*(3*n*n*n*n+6*n*n*n-3*n+1))/42;
    else if(k==7) ans=((n*n)*(n+1)*(n+1)*(3*n*n*n*n+6*n*n*n-n*n-4*n+2))/24;
    else if(k==8) ans=(n*(n+1)*(2*n+1)*(5*n*n*n*n*n*n+15*n*n*n*n*n+5*n*n*n*n-15*n*n*n-n*n+9*n-3))/90;
    else if(k==9) ans=((n*n)*(n+1)*(n+1)*(n*n+n-1)*(2*n*n*n*n+4*n*n*n-n*n-3*n+3))/20;
    else if(k==10) ans=(n*(n+1)*(2*n+1)*(n*n+n-1)*(3*n*n*n*n*n*n+9*n*n*n*n*n+2*n*n*n*n-11*n*n*n+3*n*n+10*n-5))/66;
    else{
      ans=0;
      fr(i,1,n-1){
        ans+=pow((n-i),k);
      }
      cout<<ans%mod<<"\n";
      continue;
    }

    ans-=pow(n,k);
    ans-=1;

    cout<<ans%mod<<"\n";
  }

  return 0;
}
