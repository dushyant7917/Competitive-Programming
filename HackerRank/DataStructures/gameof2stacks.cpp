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
#define MAX(a,b,c,d) max(a,max(b,max(c,d)))
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,m,x,sum,moves;
  while(t--){
    cin>>n>>m>>x;
    ll a[n],b[m];
    fr(i,0,n) cin>>a[i];
    fr(i,0,m) cin>>b[i];

    sum=0;
    ll i=0,j=0;
    while(i<n && sum+a[i]<=x) sum+=a[i++];
    moves=i;

    while(j<m){
      sum+=b[j++];
      while(sum>x && i>0) sum-=a[--i];
      if(sum<=x && i+j>moves) moves=i+j;
    }

    cout<<moves<<"\n";
  }

  return 0;
}
