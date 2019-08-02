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

ll a,b,n,m;

const ll MS=2; // Matrix Size

void multiply(ll X[MS][MS],ll Y[MS][MS]){
  ll tmp[MS][MS];

  fr(i,0,MS){
    fr(j,0,MS){
      tmp[i][j]=0;
      fr(k,0,MS) tmp[i][j]=((tmp[i][j]%m)+((X[i][k]*Y[k][j])%m))%m;
    }
  }

  fr(i,0,MS) fr(j,0,MS) X[i][j]=tmp[i][j];
}

void power(ll M[MS][MS],ll x){
  if(x==1) return;

  ll F[MS][MS]={{a%m,1},{0,1}};

  power(M,x/2);
  multiply(M,M);

  if(x&1) multiply(M,F);
}

ll F(ll n){
  if(n==0) return (1%m);

  ll M[MS][MS]={{a%m,1},{0,1}};
  power(M,n);

  return (M[0][0]*1+M[0][1]*(b%m))%m;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  while(t--){
    cin>>a>>b>>n>>m;
    cout<<F(n)<<"\n";
  }

  return 0;
}
