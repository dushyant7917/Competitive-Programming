#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e18
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,k;
  cin>>n>>k;

  ll a[n],len[n+1]={0};
  fr(i,0,n) cin>>a[i];

  rf(i,n-1,0){
    if(a[i]==1) len[i]=len[i+1]+1;
    else len[i]=0;
  }

  ll prd,sum,ans=0;

  fr(i,0,n){
    prd=1;
    sum=0;
    fr(j,i,n){
      if(a[j]==1){
        if(prd>=(sum+1)*k && prd<=(sum+len[j])*k && prd%k==0) ans++;
        sum+=len[j];
        j+=(len[j]-1);
      }
      else{
        if(prd>=INF/a[j]) break;
        prd*=a[j];
        sum+=a[j];
        if(prd==sum*k) ans++;
      }
    }
  }

  cout<<ans;

  return 0;
}
