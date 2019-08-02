#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  ll a[n+2];
  a[0]=a[n+1]=INF;
  fr(i,1,n+1) cin>>a[i];

  ll c[n+1]={0};

  fr(i,1,n+1){
    if(a[i-1]>=a[i] && a[i]<=a[i+1]) c[i]=1;
  }
  fr(i,1,n+1){
    if(a[i-1]<a[i] && a[i]<=a[i+1]) c[i]=c[i-1]+1;
  }
  rf(i,n,0){
    if(a[i-1]>=a[i] && a[i]>a[i+1]) c[i]=c[i+1]+1;
  }
  fr(i,1,n+1){
    if(a[i-1]<a[i] && a[i]>a[i+1]) c[i]=max(c[i-1],c[i+1])+1;
  }

  fr(i,1,n+1){
    c[i]+=c[i-1];
  }
  cout<<c[n];

  return 0;
}
