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
#define N 1000000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

void multiply(ll f[2][2],ll m[2][2]){
  ll c[2][2];

  fr(i,0,2){
    fr(j,0,2){
      c[i][j]=0;
      fr(k,0,2) c[i][j]=((c[i][j]%mod)+((f[i][k]*m[k][j])%mod))%mod;
    }
  }

  fr(i,0,2){
    fr(j,0,2) f[i][j]=c[i][j];
  }
}

void power(ll f[2][2],ll n){
  if(n==0 || n==1) return;

  ll m[2][2]={{1,1},{1,0}};

  power(f,n/2);
  multiply(f,f);

  if(n%2!=0) multiply(f,m);
}

ll fib(ll n){
  ll f[2][2]={{1,1},{1,0}};

  if(n==0) return 0;

  power(f,n-1);

  return f[0][0];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,m,ans;
  while(t--){
    cin>>n>>m;
    ans=(fib(m+2)-1)-(fib(n+1)-1);
    if(ans<0) cout<<ans+mod<<"\n";
    else cout<<ans<<"\n";
  }

  return 0;
}
